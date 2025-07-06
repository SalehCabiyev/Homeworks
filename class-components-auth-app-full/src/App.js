import React, { Component } from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Navbar from './components/Navbar';
import Signin from './components/Signin';
import Signup from './components/Signup';
import './App.css';

class App extends Component {
  render() {
    return (
      <Router>
        <div>
          <Navbar />
          <div className="container mt-4">
            <Routes>
              <Route path="/" element={<Signin />} />
              <Route path="/signin" element={<Signin />} />
              <Route path="/signup" element={<Signup />} />
            </Routes>
          </div>
        </div>
      </Router>
    );
  }
}

export default App;