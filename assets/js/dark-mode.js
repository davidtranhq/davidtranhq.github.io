const getTheme = () => localStorage.getItem('theme') ? localStorage.getItem('theme') : null;

document.addEventListener("DOMContentLoaded", function () {
  console.log("loaded");
  const toggleButton = document.querySelector('button.theme-switch');

  function toggleTheme(e) {
    const currentTheme = getTheme();
    console.log(`toggling: ${currentTheme}`);
    if (!currentTheme)
      return;
    const newTheme = currentTheme === 'dark' ? 'light' : 'dark';
    document.documentElement.setAttribute('data-theme', newTheme);
    localStorage.setItem('theme', newTheme);
  }

  toggleButton.addEventListener('click', toggleTheme, false);

  const currentTheme = getTheme();
  if (currentTheme) {
    document.documentElement.setAttribute('data-theme', currentTheme);
  }
});