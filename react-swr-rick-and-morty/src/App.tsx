import React from 'react';
import Home from './pages/Home';

const App: React.FC = () => {
  return (
    <div className="min-h-screen bg-gray-100">
      <h1 className="text-3xl font-bold text-center p-4">Rick and Morty Characters</h1>
      <Home />
    </div>
  );
};

export default App;