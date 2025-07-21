import React, { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import ProfileEditModal from '../components/ProfileEditModal';
import FloatingMessageButton from '../components/FloatingMessageButton';
import ChatModal from '../components/ChatModal';


interface User {
  id: string;
  name: string;
  email: string;
  avatar: string;
  bio: string;
  birthday?: string;
}

export default function ProfilePage() {
  const { id } = useParams<{ id: string }>();
  const [user, setUser] = useState<User | null>(null);
  const [editing, setEditing] = useState(false);
  const [chatOpen, setChatOpen] = useState(false);

 

  useEffect(() => {
    const storedUser = localStorage.getItem(`user_${id}`);
    if (storedUser) {
      setUser(JSON.parse(storedUser));
    } else {
      // Пример фейковых данных
      const newUser = {
        id: id!,
        name: 'Имя Фамилия',
        email: 'example@mail.com',
        avatar: `https://i.pravatar.cc/150?u=${id}`,
        bio: 'Напишите немного о себе...',
        birthday: '1990-01-01',
      };
      localStorage.setItem(`user_${id}`, JSON.stringify(newUser));
      
      setUser(newUser);
    }
  }, [id]);

  const handleSave = (data: User) => {
    setUser(data);
    localStorage.setItem(`user_${id}`, JSON.stringify(data));
  };

  const handleAvatarChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const file = e.target.files?.[0];
    if (file && user) {
      const reader = new FileReader();
      reader.onloadend = () => {
        const updatedUser = { ...user, avatar: reader.result as string };
        handleSave(updatedUser);
      };
      reader.readAsDataURL(file);
    }
  };

  if (!user) return <div className="p-6">Загрузка...</div>;

  return (
    <div className="min-h-screen bg-gray-100 py-8 px-4">
      <div className="max-w-4xl mx-auto bg-white rounded-xl shadow-xl p-6 relative">
        <div className="flex items-center justify-between">
          <div className="relative group">
            <img
              src={user.avatar}
              alt="avatar"
              className="w-32 h-32 rounded-full border-4 border-white shadow-lg object-cover cursor-pointer"
              onClick={() => document.getElementById('avatarInput')?.click()}
            />
            <input
              id="avatarInput"
              type="file"
              accept="image/*"
              onChange={handleAvatarChange}
              className="hidden"
            />
            <p className="text-sm text-center text-gray-500 mt-1 group-hover:underline">Изменить фото</p>
          </div>

          <button
            onClick={() => setEditing(true)}
            className="bg-blue-600 hover:bg-blue-700 text-white font-medium py-2 px-4 rounded-lg transition"
          >
            ✏️ Редактировать
          </button>
        </div>

        <div className="mt-6 space-y-3">
          <h1 className="text-3xl font-bold">{user.name}</h1>
          <p className="text-gray-600">📧 {user.email}</p>
          <p className="text-gray-600">🎂 Дата рождения: {user.birthday}</p>
          <p className="text-gray-800 mt-4">{user.bio}</p>
        </div>
      </div>
        {/* Список друзей */}
<div className="bg-white/30 backdrop-blur-lg rounded-3xl shadow-lg p-6 mt-6">
  <h2 className="text-2xl font-bold text-blue-700 mb-4">Друзья</h2>
  <div className="grid grid-cols-3 sm:grid-cols-4 md:grid-cols-6 gap-4">
    {[...Array(6)].map((_, i) => (
      <div key={i} className="flex flex-col items-center">
        <img
          src={`https://i.pravatar.cc/100?img=${i + 10}`}
          alt="Друг"
          className="w-16 h-16 rounded-full shadow-md"
        />
        <p className="text-white text-sm mt-2">Друг {i + 1}</p>
      </div>
    ))}
  </div>
</div>

      {/* Фотоальбом */}
<div className="bg-white/30 backdrop-blur-lg rounded-3xl shadow-lg p-6 mt-6">
  <h2 className="text-2xl font-bold text-blue-700 mb-4">Фото</h2>
  <div className="grid grid-cols-3 sm:grid-cols-4 md:grid-cols-5 gap-3">
    {[...Array(9)].map((_, i) => (
      <img
        key={i}
        src={`https://picsum.photos/200/200?random=${i}`}
        alt={`Фото ${i + 1}`}
        className="rounded-lg shadow-md hover:scale-105 transition-transform duration-300"
      />
    ))}
  </div>
</div>

      {/* Публикации */}
<div className="bg-white/30 backdrop-blur-lg rounded-3xl shadow-lg p-6 mt-6">
  <h2 className="text-2xl font-bold text-blue-700 mb-4">Публикации</h2>
  {[...Array(3)].map((_, i) => (
    <div key={i} className="bg-white/60 rounded-xl p-4 mb-4 shadow-md">
      <div className="flex items-center justify-between mb-2">
        <span className="font-semibold text-gray-800">Салех Джабиев</span>
        <span className="text-sm text-gray-500">30 августа 2023</span>
      </div>
      <p className="text-gray-700">Это пример публикации пользователя. Здесь будет ваш текст.</p>
      <div className="mt-2 text-sm text-blue-600 cursor-pointer hover:underline">
        👍 Мне нравится
      </div>
    </div>
  ))}
</div>



      {editing && (
        <ProfileEditModal
          user={user}
          onClose={() => setEditing(false)}
          onSave={handleSave}
        />
      )}

      

      
      {chatOpen && (
  <ChatModal userName={user.name} onClose={() => setChatOpen(false)} />
)}

<FloatingMessageButton onClick={() => setChatOpen(true)} />

    </div>
  );
}
