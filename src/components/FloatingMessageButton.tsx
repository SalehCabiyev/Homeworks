import React from 'react';
import { FaFacebookMessenger } from 'react-icons/fa';

interface FloatingMessageButtonProps {
  onClick: () => void;
  unreadCount?: number;
}

export default function FloatingMessageButton({
  onClick,
  unreadCount = 0,
}: FloatingMessageButtonProps) {
  return (
    <div className="fixed bottom-6 right-6 z-50">
      <button
        onClick={onClick}
        title="Написать сообщение"
        className="relative bg-blue-600 hover:bg-blue-700 text-white rounded-full p-4 shadow-xl transition transform hover:scale-110 animate-pulse"
      >
        <FaFacebookMessenger
          {...({ className: 'text-2xl' } as any)}
        />

        {unreadCount > 0 && (
          <span className="absolute -top-1 -right-1 bg-red-600 text-white text-xs font-bold px-2 py-0.5 rounded-full animate-bounce">
            {unreadCount}
          </span>
        )}
      </button>
    </div>
  );
}
