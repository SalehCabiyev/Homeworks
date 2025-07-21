// src/components/ChatModal.tsx
import React, { useState } from 'react';
import { FaSmile, FaPaperclip, FaPaperPlane } from 'react-icons/fa';
import { IoMdClose } from 'react-icons/io';

interface ChatModalProps {
  onClose: () => void;
  userName: string;
}

export default function ChatModal({ onClose, userName }: ChatModalProps) {
  const [message, setMessage] = useState('');
  const [messages, setMessages] = useState<string[]>([]);
  const [search, setSearch] = useState('');

  const sendMessage = () => {
    if (!message.trim()) return;
    setMessages((prev) => [...prev, message]);
    setMessage('');
  };

  return (
    <div className="fixed bottom-20 right-6 z-50 w-80 bg-white dark:bg-gray-800 border border-gray-300 dark:border-gray-700 rounded-xl shadow-lg flex flex-col overflow-hidden">
      {/* Header */}
      <div className="flex justify-between items-center p-3 border-b border-gray-300 dark:border-gray-600 bg-gray-100 dark:bg-gray-700">
        <div className="text-sm text-gray-800 dark:text-white font-semibold">
          Чат с {userName}
        </div>
        <button onClick={onClose} className="text-gray-500 hover:text-red-500">
          <IoMdClose size={20} />
        </button>
      </div>

      {/* Поиск */}
      <div className="p-2 bg-white dark:bg-gray-800 border-b border-gray-200 dark:border-gray-700">
        <input
          type="text"
          value={search}
          onChange={(e) => setSearch(e.target.value)}
          placeholder="Поиск собеседника..."
          className="w-full p-2 text-sm rounded-lg border border-gray-300 dark:border-gray-600 bg-gray-50 dark:bg-gray-700 text-gray-800 dark:text-white"
        />
      </div>

      {/* Messages */}
      <div className="flex-1 p-3 space-y-2 overflow-y-auto bg-gray-50 dark:bg-gray-700 text-sm">
        {messages.map((msg, idx) => (
          <div
            key={idx}
            className="bg-blue-100 dark:bg-blue-600 text-black dark:text-white px-3 py-2 rounded-xl w-fit"
          >
            {msg}
          </div>
        ))}
      </div>

      {/* Input section */}
      <div className="flex items-center p-3 border-t border-gray-300 dark:border-gray-600 bg-white dark:bg-gray-800">
        <button className="text-gray-500 hover:text-blue-600 mr-2">
          <FaSmile size={18} />
        </button>
        <button className="text-gray-500 hover:text-blue-600 mr-2">
          <FaPaperclip size={18} />
        </button>
        <input
          type="text"
          placeholder="Введите сообщение..."
          value={message}
          onChange={(e) => setMessage(e.target.value)}
          onKeyDown={(e) => e.key === 'Enter' && sendMessage()}
          className="flex-1 p-2 rounded-lg border border-gray-300 dark:border-gray-600 bg-gray-50 dark:bg-gray-700 text-sm text-gray-800 dark:text-white"
        />
        <button
          onClick={sendMessage}
          className="text-blue-600 hover:text-blue-800 ml-2"
          title="Отправить"
        >
          <FaPaperPlane size={18} />
        </button>
      </div>
    </div>
  );
}
