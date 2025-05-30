//работает только по этой ссылке
//http://localhost:3000/login.html


const express = require('express');
const fs = require('fs');
const bcrypt = require('bcryptjs');
const session = require('express-session');
const cors = require('cors');
const app = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());
app.use(express.static('public'));
app.use(session({
  secret: 'secret_key',
  resave: false,
  saveUninitialized: true
}));

function readUsers() {
  return JSON.parse(fs.readFileSync('users.json', 'utf8'));
}

function writeUsers(users) {
  fs.writeFileSync('users.json', JSON.stringify(users, null, 2));
}

app.post('/register', async (req, res) => {
  const { email, password, name } = req.body;
  const users = readUsers();
  if (users.find(u => u.email === email)) {
    return res.status(400).json({ message: 'Пользователь уже существует' });
  }
  const hash = await bcrypt.hash(password, 10);
  users.push({ email, password: hash, name, coords: null });
  writeUsers(users);
  res.json({ message: 'Регистрация успешна' });
});

app.post('/login', async (req, res) => {
  const { email, password } = req.body;
  const users = readUsers();
  const user = users.find(u => u.email === email);
  if (!user || !(await bcrypt.compare(password, user.password))) {
    return res.status(401).json({ message: 'Неверный логин или пароль' });
  }
  req.session.user = user;
  res.json({ message: 'Успешный вход', user });
});

app.post('/save-location', (req, res) => {
  const { email, coords } = req.body;
  const users = readUsers();
  const user = users.find(u => u.email === email);
  if (user) {
    user.coords = coords;
    writeUsers(users);
    res.json({ message: 'Местоположение сохранено' });
  } else {
    res.status(404).json({ message: 'Пользователь не найден' });
  }
});

app.listen(PORT, () => console.log(`Server started on http://localhost:${PORT}`));

//http://localhost:3000/register.html
