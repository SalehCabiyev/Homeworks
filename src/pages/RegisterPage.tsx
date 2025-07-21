import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function RegisterPage() {
  const [firstName, setFirstName] = useState('');
  const [lastName, setLastName] = useState('');
  const [birthDate, setBirthDate] = useState('');
  const [gender, setGender] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const navigate = useNavigate();

  const handleRegister = (e: React.FormEvent) => {
    e.preventDefault();

    const user = {
      id: 1,
      name: `${firstName} ${lastName}`,
      email,
      birthDate,
      gender,
    };
    localStorage.setItem('user', JSON.stringify(user));
    navigate('/login');
  };

  return (
    <div className="min-h-screen flex items-center justify-center bg-gray-100 dark:bg-gray-900 px-4">
      <div className="max-w-lg w-full bg-white dark:bg-gray-800 rounded-xl shadow-xl p-8">
        <h1 className="text-3xl font-bold text-center text-gray-900 dark:text-white mb-1">
          Создайте новый аккаунт
        </h1>
        <p className="text-center text-gray-600 dark:text-gray-300 mb-6">Это быстро и просто.</p>

        <form onSubmit={handleRegister} className="space-y-4">
          <div className="flex gap-3">
            <input
              type="text"
              placeholder="Имя"
              value={firstName}
              onChange={(e) => setFirstName(e.target.value)}
              className="w-1/2 p-3 border rounded-md bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white"
              required
            />
            <input
              type="text"
              placeholder="Фамилия"
              value={lastName}
              onChange={(e) => setLastName(e.target.value)}
              className="w-1/2 p-3 border rounded-md bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white"
              required
            />
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Дата рождения</label>
            <input
              type="date"
              value={birthDate}
              onChange={(e) => setBirthDate(e.target.value)}
              className="w-full p-3 border rounded-md bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white"
              required
            />
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 dark:text-gray-300 mb-1">Пол</label>
            <div className="flex gap-4">
              <label className="flex items-center gap-2">
                <input type="radio" name="gender" value="Женщина" onChange={(e) => setGender(e.target.value)} required />
                <span className="text-gray-700 dark:text-gray-300">Женщина</span>
              </label>
              <label className="flex items-center gap-2">
                <input type="radio" name="gender" value="Мужчина" onChange={(e) => setGender(e.target.value)} required />
                <span className="text-gray-700 dark:text-gray-300">Мужчина</span>
              </label>
              <label className="flex items-center gap-2">
                <input type="radio" name="gender" value="Другое" onChange={(e) => setGender(e.target.value)} required />
                <span className="text-gray-700 dark:text-gray-300">Другое</span>
              </label>
            </div>
          </div>

          <input
            type="email"
            placeholder="Номер мобильного телефона или эл. адрес"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            className="w-full p-3 border rounded-md bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white"
            required
          />

          <input
            type="password"
            placeholder="Новый пароль"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            className="w-full p-3 border rounded-md bg-gray-100 dark:bg-gray-700 dark:border-gray-600 dark:text-white"
            required
          />

          <p className="text-xs text-gray-500 dark:text-gray-400">
            Люди, которые пользуются нашим сервисом, могли загрузить вашу контактную информацию на Facebook. 
            <a href="#" className="text-blue-600 hover:underline ml-1">Подробнее</a>
          </p>

          <p className="text-xs text-gray-500 dark:text-gray-400">
            Нажимая кнопку "Зарегистрироваться", вы принимаете наши 
            <a href="#" className="text-blue-600 hover:underline mx-1">Условия использования</a>, 
            <a href="#" className="text-blue-600 hover:underline mx-1">Политику конфиденциальности</a> и 
            <a href="#" className="text-blue-600 hover:underline mx-1">Политику в отношении файлов cookie</a>.
            Вы можете получать от нас SMS-уведомления, отказаться от которых можно в любой момент.
          </p>

          <button
            type="submit"
            className="w-full bg-green-600 hover:bg-green-700 text-white font-semibold py-3 rounded-lg transition duration-200"
          >
            Зарегистрироваться
          </button>

          <p className="text-sm text-center text-gray-700 dark:text-gray-300 mt-4">
            У вас уже есть аккаунт?{' '}
            <a href="/login" className="text-blue-600 hover:underline">Войти</a>
          </p>
        </form>
      </div>
    </div>
  );
}
