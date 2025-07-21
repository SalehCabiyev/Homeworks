import React, { useState } from 'react';

interface PostFormProps {
  onAddPost: (content: string) => void;
}

export default function PostForm({ onAddPost }: PostFormProps) {
  const [content, setContent] = useState('');

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!content.trim()) return;
    onAddPost(content);
    setContent('');
  };

  return (
    <form onSubmit={handleSubmit} className="bg-white dark:bg-gray-800 p-4 rounded-lg shadow mb-6">
      <textarea
        value={content}
        onChange={(e) => setContent(e.target.value)}
        placeholder="Что у вас нового?"
        className="w-full p-3 border border-gray-300 dark:border-gray-700 rounded-lg bg-gray-100 dark:bg-gray-900 text-sm text-gray-800 dark:text-white resize-none focus:outline-none focus:ring-2 focus:ring-blue-400"
        rows={3}
      />
      <button
        type="submit"
        className="mt-3 bg-blue-600 text-white px-4 py-2 rounded hover:bg-blue-700"
      >
        Опубликовать
      </button>
    </form>
  );
}
