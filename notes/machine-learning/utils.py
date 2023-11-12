import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.model_selection import train_test_split, cross_val_score, KFold
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.metrics import roc_curve
from scipy.stats import t

def class_distribution(df, target):
    return df[target].value_counts()

def baseline_accuracy(df, target):
    return df[target].value_counts(normalize=True).max()

def train_test_split_df(df, target, test_size, seed=0):
    X = df.drop(target, axis='columns').values
    y = df['target'].values
    return train_test_split(X, y, test_size=test_size, random_state=seed)

def evaluate_model(model, X_test, y_test, threshold):
    classes = model.classes_
    yhat = classes[(model.predict_proba(X_test) > threshold).astype(int)]
    tp = sum(np.logical_and(yhat == classes[1], y_test == classes[1]))
    tn = sum(np.logical_and(yhat == classes[0], y_test == classes[0]))
    fp = sum(np.logical_and(yhat == classes[1], y_test == classes[0]))
    fn = sum(np.logical_and(yhat == classes[0], y_test == classes[1]))

    print(f"tp: {tp} tn: {tn} fp: {fp} fn: {fn}")
    
    # Accuracy
    acc = (tp + tn) / (tp + tn + fp + fn)
    
    # Precision
    # "Of the ones I labeled +, how many are actually +?"
    precision = tp / (tp + fp)
    
    # Recall
    # "Of all the + in the data, how many do I correctly label?"
    recall = tp / (tp + fn)    
    
    # Sensitivity
    # "Of all the + in the data, how many do I correctly label?"
    sensitivity = recall
    
    # Specificity
    # "Of all the - in the data, how many do I correctly label?"
    specificity = tn / (fp + tn)

    return (acc, precision, recall, sensitivity, specificity)

def graph_roc(model, X_test, y_test, pos_class_idx):
    fpr, tpr, _ = roc_curve(y_test, 
                            model.predict_proba(X_test)[:, 1], 
                            pos_label=model.classes_[pos_class_idx])
    ax = sns.lineplot(x=fpr, y=tpr)
    ax.set_xlabel('FP rate')
    ax.set_ylabel('TP rate')
    return ax

def clt_ci(data):
    stderr = np.std(data) / np.sqrt(len(data))
    critval = 1.96
    mu = data.mean()
    norm_ci = (mu - critval*stderr, mu + critval*stderr)

    return norm_ci
    
def t_ci(data, alpha):
    alpha = (5/100)
    crit_val = 1-(alpha/2)


    # Degrees of freedom (dof) of an estimate is the number of independent
    # pieces of information that went into calculating the estimate.
    n = len(data)
    dof = n-1
    # the precise shape of the t distribution depends on dof, which is related to the sample size.

    # ppf: percent point function (inverse of cdf — percentiles).
    # It returns the value x of the variable that has a given cumulative distribution probability (cdf).
    # Thus, given the cdf(x) of a x value, ppf returns the value x itself, therefore, operating as the inverse of cdf.
    t_value = t.ppf(crit_val, df=dof) # 1st arg: critical value; 2nd arg: dof

    stderr = np.std(data) / np.sqrt(n)

    ci = data.mean() + t_value * stderr * np.array([-1, 1])

    return ci

def bootstrap_means(data, numboot=1000):
    n = len(data)
    boot_means = np.zeros(numboot)
    for i in range(numboot):
        d = data.sample(n, replace=True)
        boot_means[i] = d.mean()
    return boot_means

def bootstrap_ci(data, cl=0.95, num_boot=1000):
    """Create bootstrap CI with confidence level 95%"""
    boot_means = bootstrap_means(data, num_boot)
    p_1 = (1 - cl)/2
    p_2 = 1-p_1

    boot_means_df = pd.DataFrame(data=boot_means - data.mean(), columns=['samples'])
    boot_quant = np.quantile(boot_means_df, [p_1, p_2])

    ci = (data.mean() - boot_quant[1], data.mean() - boot_quant[0])
    return ci

def category_to_numeric(data, category):
    encoded = data.copy()
    encoded[category] = LabelEncoder().fit_transform(encoded[category])
    return encoded

def numeric_to_one_hot_encoded(data, category):
    # manually
    # data_ohe = data.copy()
    # # reshape category array to 2D for fit_transform
    # X = OneHotEncoder().fit_transform(data_ohe[category].values.reshape(-1, 1)).toarray()
    # num_categories = X.shape[1]
    # df_one_hot = pd.DataFrame(X, columns=[category + str(int(i)) for i in range(num_categories)])
    # data_ohe = pd.concat([data_ohe, df_one_hot], axis=1)

    encoded = data.copy()
    encoded = pd.get_dummies(encoded, drop_first=True)
    return encoded

def test_common_prefix()