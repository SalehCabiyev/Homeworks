// src/components/Navbar.tsx
import React, { useEffect, useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { FaFacebook, FaBell, FaHome, FaUser } from 'react-icons/fa';
import ThemeToggle from './ThemeToggle';
import { FaUserFriends } from 'react-icons/fa';

export default function Navbar() {
  const navigate = useNavigate();
  const user = JSON.parse(localStorage.getItem('user') || '{}');
  const [scrolled, setScrolled] = useState(false);

  // Отслеживаем прокрутку страницы
  useEffect(() => {
    const onScroll = () => {
      setScrolled(window.scrollY > 10);
    };
    window.addEventListener('scroll', onScroll);
    return () => window.removeEventListener('scroll', onScroll);
  }, []);

  const logout = () => {
    localStorage.removeItem('user');
    navigate('/login');
  };

  return (
    <nav
      className={`transition-all duration-300 sticky top-0 z-50 px-6 py-3 flex items-center justify-between ${
        scrolled
          ? 'bg-white/80 dark:bg-gray-900/80 backdrop-blur shadow-md'
          : 'bg-white dark:bg-gray-900'
      }`}
    >
      {/* Логотип и ссылки */}
      <div className="flex items-center gap-6">
        <Link to="/" className="flex items-center gap-2 text-blue-600 text-2xl font-bold">
          <FaFacebook {...({} as any)} className="text-3xl" />
          <span className="hidden sm:inline text-xl text-gray-800 dark:text-white">Facebook</span>
        </Link>

        <Link to="/" className="text-gray-700 dark:text-white hover:text-blue-600 text-xl" title="Лента">
          <FaHome />
        </Link>
        <Link
          to={`/profile/${user.id || 1}`}
          className="text-gray-700 dark:text-white hover:text-blue-600 text-xl"
          title="Профиль"
        >
            <FaUser />
            </Link>
            <Link to="/friends" title="Друзья" className="text-gray-700 dark:text-white hover:text-blue-600 text-xl">
            <FaUserFriends />
            </Link>
        <button
          title="Уведомления"
          className="text-gray-700 dark:text-white hover:text-blue-600 text-xl"
        >
          <FaBell />
        </button>
      </div>

      {/* Правая часть */}
      <div className="flex items-center gap-4">
        <ThemeToggle />

        {user && (
          <div className="flex items-center gap-2">
            <img
              src={user.avatar || `https://i.pravatar.cc/40?u=${user.email}`}
              alt="avatar"
              className="w-8 h-8 rounded-full object-cover border"
            />
           
          </div>
        )}

        <button
          onClick={logout}
          className="text-sm bg-blue-500 hover:bg-blue-600 text-white px-3 py-1 rounded transition"
        >
          Выйти
        </button>
      </div>
    </nav>
  );
}
