import React, { useState } from 'react';
import { useCharacters } from '../hooks/useCharacters';
import Card from '../components/Card';

const Home: React.FC = () => {
  const [search, setSearch] = useState("");
  const { characters, isLoading, isError } = useCharacters(search);

  return (
    <div className="p-4">
      <input
        type="text"
        placeholder="Search by name..."
        className="p-2 border rounded mb-4 w-full max-w-md"
        value={search}
        onChange={(e) => setSearch(e.target.value)}
      />

      {isLoading && <p>Loading...</p>}
      {isError && <p>Error loading characters</p>}

      <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 gap-4">
        {characters.map((char: any) => (
          <Card
            key={char.id}
            name={char.name}
            image={char.image}
            status={char.status}
            species={char.species}
          />
        ))}
      </div>
    </div>
  );
};

export default Home;