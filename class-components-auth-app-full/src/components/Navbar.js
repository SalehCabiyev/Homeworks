import React, { Component } from 'react';
import { Link } from 'react-router-dom';

class Navbar extends Component {
  render() {
    return (
      <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
        <div className="container">
          <Link className="navbar-brand" to="/">AuthApp</Link>
          <div>
            <ul className="navbar-nav me-auto">
              <li className="nav-item">
                <Link className="nav-link" to="/signin">Sign In</Link>
              </li>
              <li className="nav-item">
                <Link className="nav-link" to="/signup">Sign Up</Link>
              </li>
            </ul>
          </div>
        </div>
      </nav>
    );
  }
}

export default Navbar;