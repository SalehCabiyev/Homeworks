import React, { Component } from 'react';

class Signin extends Component {
  constructor(props) {
    super(props);
    this.state = {
      email: '',
      password: ''
    };
  }

  handleChange = (e) => {
    this.setState({ [e.target.name]: e.target.value });
  }

  handleSubmit = (e) => {
    e.preventDefault();
    alert(`Signed in with ${this.state.email}`);
  }

  render() {
    return (
      <div className="card p-4">
        <h2>Sign In</h2>
        <form onSubmit={this.handleSubmit}>
          <div className="mb-3">
            <label>Email:</label>
            <input type="email" className="form-control" name="email" onChange={this.handleChange} value={this.state.email} required />
          </div>
          <div className="mb-3">
            <label>Password:</label>
            <input type="password" className="form-control" name="password" onChange={this.handleChange} value={this.state.password} required />
          </div>
          <button type="submit" className="btn btn-primary">Sign In</button>
        </form>
      </div>
    );
  }
}

export default Signin;