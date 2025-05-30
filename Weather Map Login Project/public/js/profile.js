let map;
function initMap() {
  map = new google.maps.Map(document.getElementById("map"), {
    center: { lat: 55.751244, lng: 37.618423 },
    zoom: 8,
  });

  map.addListener("click", (e) => {
    const user = JSON.parse(localStorage.getItem("user"));
    const coords = { lat: e.latLng.lat(), lng: e.latLng.lng() };

    fetch('/save-location', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ email: user.email, coords })
    }).then(() => {
      alert("Адрес сохранён");
      window.location.href = 'weather.html';
    });
  });
}