// src/pages/FriendsPage.tsx
import React, { useState, useEffect } from 'react';

interface Friend {
  id: number;
  name: string;
  avatar: string;
  isFriend: boolean;
}

export default function FriendsPage() {
  const [allUsers, setAllUsers] = useState<Friend[]>([]);
  const [filter, setFilter] = useState<'all' | 'friends' | 'others'>('all');
  const [search, setSearch] = useState('');

  useEffect(() => {
    const fakeUsers: Friend[] = Array.from({ length: 15 }, (_, i) => ({
      id: i + 1,
      name: `Пользователь ${i + 1}`,
      avatar: `https://i.pravatar.cc/150?img=${i + 10}`,
      isFriend: Math.random() > 0.5,
    }));

    setAllUsers(fakeUsers);
  }, []);

  const filtered = allUsers.filter((user) => {
    const matchesSearch = user.name.toLowerCase().includes(search.toLowerCase());
    const matchesFilter =
      filter === 'all' ||
      (filter === 'friends' && user.isFriend) ||
      (filter === 'others' && !user.isFriend);

    return matchesSearch && matchesFilter;
  });

  const toggleFriend = (id: number) => {
    setAllUsers((prev) =>
      prev.map((user) =>
        user.id === id ? { ...user, isFriend: !user.isFriend } : user
      )
    );
  };

  return (
    <div className="p-6 max-w-5xl mx-auto">
      <h2 className="text-2xl font-bold mb-4">Друзья</h2>

      {/* Панель фильтра и поиска */}
      <div className="flex flex-col sm:flex-row sm:items-center sm:justify-between gap-4 mb-6">
        <input
          type="text"
          placeholder="Поиск друзей..."
          className="px-4 py-2 border rounded-md w-full sm:w-64"
          value={search}
          onChange={(e) => setSearch(e.target.value)}
        />

        <div className="flex gap-2">
          <button
            className={`px-4 py-2 rounded ${
              filter === 'all' ? 'bg-blue-600 text-white' : 'bg-gray-200'
            }`}
            onClick={() => setFilter('all')}
          >
            Все
          </button>
          <button
            className={`px-4 py-2 rounded ${
              filter === 'friends' ? 'bg-blue-600 text-white' : 'bg-gray-200'
            }`}
            onClick={() => setFilter('friends')}
          >
            Друзья
          </button>
          <button
            className={`px-4 py-2 rounded ${
              filter === 'others' ? 'bg-blue-600 text-white' : 'bg-gray-200'
            }`}
            onClick={() => setFilter('others')}
          >
            Не в друзьях
          </button>
        </div>
      </div>

      {/* Количество друзей */}
      <p className="mb-4 text-gray-600">
        Всего друзей: {allUsers.filter((u) => u.isFriend).length}
      </p>

      {/* Список пользователей */}
      <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-4 gap-6">
        {filtered.map((user) => (
          <div
            key={user.id}
            className="bg-white dark:bg-gray-800 p-4 rounded-lg shadow text-center"
          >
            <img
              src={user.avatar}
              alt={user.name}
              className="w-20 h-20 rounded-full mx-auto mb-3"
            />
            <h3 className="text-lg font-semibold mb-1 text-gray-800 dark:text-white">
              {user.name}
            </h3>
            <button
              onClick={() => toggleFriend(user.id)}
              className={`px-3 py-1 rounded text-sm ${
                user.isFriend
                  ? 'bg-red-500 text-white hover:bg-red-600'
                  : 'bg-blue-500 text-white hover:bg-blue-600'
              }`}
            >
              {user.isFriend ? 'Удалить из друзей' : 'Добавить в друзья'}
            </button>
          </div>
        ))}
      </div>
    </div>
  );
}
