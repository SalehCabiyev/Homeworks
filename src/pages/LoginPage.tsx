import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function LoginPage() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const navigate = useNavigate();

  const handleLogin = (e: React.FormEvent) => {
    e.preventDefault();
    if (!email || !password) return;

    localStorage.setItem('user', JSON.stringify({ email, name: email.split('@')[0] }));
    navigate('/');
  };

  return (
    <div className="min-h-screen flex items-center justify-center bg-gray-100 dark:bg-gray-900 px-4">
      <div className="max-w-4xl w-full grid grid-cols-1 md:grid-cols-2 gap-10 items-center">
        {/* Левая часть с логотипом и текстом */}
        <div className="text-center md:text-left">
          <h1 className="text-5xl font-bold text-blue-600 mb-4">Facebook</h1>
          <p className="text-xl text-gray-700 dark:text-gray-300">
            Помогает вам всегда оставаться на связи с близкими.
          </p>
        </div>

        {/* Правая часть - форма */}
        <div className="bg-white dark:bg-gray-800 p-8 rounded-xl shadow-2xl w-full">
          <h2 className="text-2xl font-semibold text-center text-gray-800 dark:text-white mb-6">
            Вход в аккаунт
          </h2>
          <form onSubmit={handleLogin} className="space-y-4">
            <div>
              <input
                type="email"
                className="w-full px-4 py-2 border rounded-lg bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                value={email}
                onChange={(e) => setEmail(e.target.value)}
                placeholder="Email"
                required
              />
            </div>
            <div>
              <input
                type="password"
                className="w-full px-4 py-2 border rounded-lg bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white focus:outline-none focus:ring-2 focus:ring-blue-500"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                placeholder="Пароль"
                required
              />
            </div>
            <button
              type="submit"
              className="w-full bg-blue-600 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded-lg transition duration-200"
            >
              Войти
            </button>
          </form>
          <p className="mt-6 text-sm text-center text-gray-500 dark:text-gray-400">
            Нет аккаунта?{' '}
            <a href="/register" className="text-blue-500 hover:underline">
              Зарегистрируйтесь
            </a>
          </p>
        </div>
      </div>
    </div>
  );
}
