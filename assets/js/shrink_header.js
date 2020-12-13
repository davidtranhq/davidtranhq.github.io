window.onscroll = function() {
    if (window.pageYOffset 
        || document.documentElement.scrollTop 
        || document.body.scrollTop || 0) {
        document.getElementById('navbar').classList.add('small');
    }
    else {
        document.getElementById('navbar').classList.remove('small');
    }
}