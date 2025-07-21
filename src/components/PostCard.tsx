import React, { useState } from 'react';

interface Props {
  id: number;
  author: string;
  content: string;
  likes: number;
}

export default function PostCard({ author, content, likes: initialLikes }: Props) {
  const [likes, setLikes] = useState(initialLikes);
  const [liked, setLiked] = useState(false);

  const toggleLike = () => {
    setLikes(liked ? likes - 1 : likes + 1);
    setLiked(!liked);
  };

  return (
    <div className="bg-white dark:bg-gray-800 p-4 rounded-lg shadow mb-4">
      <div className="flex items-center gap-3 mb-2">
        <img
          src={`https://i.pravatar.cc/150?u=${author}`}
          alt="avatar"
          className="w-10 h-10 rounded-full"
        />
        <div>
          <h3 className="font-semibold text-gray-900 dark:text-white">{author}</h3>
          <p className="text-xs text-gray-500">только что</p>
        </div>
      </div>
      <p className="text-gray-800 dark:text-gray-300">{content}</p>
      <button
        onClick={toggleLike}
        className={`mt-3 text-sm ${
          liked ? 'text-red-500' : 'text-gray-500'
        } hover:underline`}
      >
        ❤️ {likes} Нравится
      </button>
    </div>
  );
}
