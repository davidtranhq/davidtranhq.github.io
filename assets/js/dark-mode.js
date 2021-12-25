const getTheme = () => localStorage.getItem('theme') ? localStorage.getItem('theme') : null;

document.addEventListener("DOMContentLoaded", function () {
  const toggleButton = document.querySelector('button.theme-switch');

  function toggleTheme(e) {
    const currentTheme = getTheme();
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