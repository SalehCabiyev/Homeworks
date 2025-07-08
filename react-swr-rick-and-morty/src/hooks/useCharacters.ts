import useSWR from "swr";
import axios from "axios";

const fetcher = (url: string) => axios.get(url).then(res => res.data);

export function useCharacters(name: string = "") {
  const { data, error, isLoading, mutate } = useSWR(
    `https://rickandmortyapi.com/api/character/?name=${name}`,
    fetcher
  );

  return {
    characters: data?.results || [],
    isLoading,
    isError: error,
    mutate
  };
}