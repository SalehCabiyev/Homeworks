const apiKey = '2f702e993ff233af0858486a46fcc8e0';
let currentPage = 1;
const citiesPerPage = 5;

async function fetchWeather() {
  const user = JSON.parse(localStorage.getItem("user"));
  if (!user || !user.coords) return;

  const { lat, lng } = user.coords;
  const res = await fetch(`http://api.openweathermap.org/data/2.5/find?lat=${lat}&lon=${lng}&cnt=50&units=metric&appid=${apiKey}`);
  const data = await res.json();

  const cities = data.list;
  showCities(cities);
}

function showCities(cities) {
  const container = document.getElementById("weather-container");
  const pagination = document.getElementById("pagination");
  container.innerHTML = '';
  pagination.innerHTML = '';

  const start = (currentPage - 1) * citiesPerPage;
  const pageCities = cities.slice(start, start + citiesPerPage);

  pageCities.forEach(city => {
    const div = document.createElement("div");
    div.className = "bg-white p-4 rounded-xl shadow";
    div.innerHTML = `
      <h2 class="text-xl font-bold">${city.name}</h2>
      <p>Температура: ${city.main.temp}°C</p>
      <p>Погода: ${city.weather[0].description}</p>
      <p>Ветер: ${city.wind.speed} м/с</p>
      <p>Влажность: ${city.main.humidity}%</p>
    `;
    container.appendChild(div);
  });

  const totalPages = Math.ceil(cities.length / citiesPerPage);
  for (let i = 1; i <= totalPages; i++) {
    const btn = document.createElement("button");
    btn.textContent = i;
    btn.className = `px-3 py-1 rounded ${i === currentPage ? 'bg-blue-600 text-white' : 'bg-white border'}`;
    btn.onclick = () => {
      currentPage = i;
      showCities(cities);
    };
    pagination.appendChild(btn);
  }
}

document.addEventListener("DOMContentLoaded", fetchWeather);

