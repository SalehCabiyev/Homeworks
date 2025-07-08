import React from 'react';

interface CardProps {
  name: string;
  image: string;
  status: string;
  species: string;
}

const Card: React.FC<CardProps> = ({ name, image, status, species }) => {
  return (
    <div className="bg-white shadow-md rounded-xl p-4 flex flex-col items-center">
      <img src={image} alt={name} className="rounded-full w-24 h-24 mb-4" />
      <h2 className="font-bold text-lg">{name}</h2>
      <p className="text-sm">{species} — {status}</p>
    </div>
  );
};

export default Card;