import React from 'react';
import { useDarkMode } from '../hooks/useDarkMode';

export default function ThemeToggle() {
  const { darkMode, toggle } = useDarkMode();

  return (
    <button
      onClick={toggle}
      className="bg-white dark:bg-gray-700 text-gray-800 dark:text-white px-3 py-1 rounded-lg shadow hover:bg-gray-200 dark:hover:bg-gray-600 transition"
      type="button"
    >
      {darkMode ? '☀️ Светлая' : '🌙 Тёмная'}
    </button>
  );
}
