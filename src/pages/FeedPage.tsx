import React, { useEffect, useState } from 'react';
import PostCard from '../components/PostCard';
import PostForm from '../components/PostForm';
import FloatingMessageButton from '../components/FloatingMessageButton';
import ChatModal from '../components/ChatModal';
import {
  FaUserFriends, FaRobot, FaClock, FaBookmark, FaFilm,
  FaStore, FaNewspaper, FaCalendarAlt, FaBullhorn
} from 'react-icons/fa';

interface Post {
  id: number;
  author: string;
  content: string;
  likes: number;
}

export default function FeedPage() {
  const [posts, setPosts] = useState<Post[]>([]);
  const [chatOpen, setChatOpen] = useState(false);
  const user = JSON.parse(localStorage.getItem('user') || '{}');

  useEffect(() => {
    const saved = localStorage.getItem('posts');
    if (saved) setPosts(JSON.parse(saved));
  }, []);

  useEffect(() => {
    localStorage.setItem('posts', JSON.stringify(posts));
  }, [posts]);

  const handleAddPost = (content: string) => {
    const newPost: Post = {
      id: Date.now(),
      author: user.name || 'Anon',
      content,
      likes: 0,
    };
    setPosts([newPost, ...posts]);
  };

  return (
    <div className="flex bg-gray-100 dark:bg-gray-900 min-h-screen">
      {/* Левая панель (меню) */}
      <aside className="w-64 hidden lg:block p-4 text-gray-800 dark:text-white space-y-4">
        <h2 className="text-lg font-semibold mb-2">Меню</h2>
        <div className="space-y-2">
          <SidebarItem icon={<FaUserFriends />} label="Друзья" />
          <SidebarItem icon={<FaRobot />} label="Meta AI" />
          <SidebarItem icon={<FaClock />} label="Воспоминания" />
          <SidebarItem icon={<FaBookmark />} label="Сохранённое" />
          <SidebarItem icon={<FaFilm />} label="Reels" />
          <SidebarItem icon={<FaStore />} label="Marketplace" />
          <SidebarItem icon={<FaNewspaper />} label="Ленты" />
          <SidebarItem icon={<FaCalendarAlt />} label="Мероприятия" />
          <SidebarItem icon={<FaBullhorn />} label="Ads Manager" />
        </div>
      </aside>

      {/* Центр — лента новостей */}
      <main className="flex-1 max-w-2xl mx-auto p-4">
        <h2 className="text-xl font-bold text-gray-800 dark:text-white mb-4">Новости</h2>
        <PostForm onAddPost={handleAddPost} />
        {posts.length > 0 ? (
          posts.map((post) => <PostCard key={post.id} {...post} />)
        ) : (
          <p className="text-gray-500 dark:text-gray-400">Нет постов</p>
        )}
      </main>

      {/* Правая панель (реклама) */}
      <aside className="w-72 hidden xl:block p-4 space-y-4">
        <h2 className="text-lg font-semibold text-gray-700 dark:text-white">Реклама</h2>
        <AdCard
          img="https://source.unsplash.com/300x200/?technology"
          text="Прокачай свои навыки с курсом по React!"
        />
        <AdCard
          img="https://source.unsplash.com/300x200/?travel"
          text="Планируй отдых вместе с нами!"
        />
      </aside>

      {/* Плавающая кнопка */}
      <FloatingMessageButton onClick={() => setChatOpen(true)} unreadCount={2} />

      {/* Модалка чата */}
      {chatOpen && (
        <ChatModal userName={user.name || 'Друг'} onClose={() => setChatOpen(false)} />
      )}
    </div>
  );
}

// Подкомпонент для бокового пункта меню
function SidebarItem({ icon, label }: { icon: React.ReactNode; label: string }) {
  return (
    <div className="flex items-center gap-3 hover:bg-gray-200 dark:hover:bg-gray-800 p-2 rounded cursor-pointer">
      {icon}
      <span>{label}</span>
    </div>
  );
}

// Подкомпонент для рекламного блока
function AdCard({ img, text }: { img: string; text: string }) {
  return (
    <div className="bg-white dark:bg-gray-800 rounded-lg shadow-md overflow-hidden">
      <img src={img} alt="ad" className="w-full h-32 object-cover" />
      <p className="p-3 text-sm text-gray-800 dark:text-white">{text}</p>
    </div>
  );
}
