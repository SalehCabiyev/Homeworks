const images = [
  'images/img1.jpg',
  'images/img2.jpg',
  'images/img3.jpg',
  'images/img4.jpg',
  'images/img5.jpg'
];

const carousel = document.getElementById('carousel');
let currentIndex = 0;

function loadCarousel() {
  carousel.innerHTML = '';
  images.forEach((src, index) => {
    const slide = document.createElement('div');
    slide.className = 'slide';
    slide.id = `slide-${index}`;
    if (index === currentIndex) slide.classList.add('active');
    slide.style.backgroundImage = `url('${src}')`;
    carousel.appendChild(slide);
  });
}

function showSlide(index) {
  const slides = document.querySelectorAll('.slide');
  slides.forEach(slide => slide.classList.remove('active'));
  currentIndex = (index + images.length) % images.length;
  slides[currentIndex].classList.add('active');
}

function nextSlide() {
  showSlide(currentIndex + 1);
}

function prevSlide() {
  showSlide(currentIndex - 1);
}

function searchImages() {
  alert('Поиск не реализован в этой демонстрации.');
}

loadCarousel();
