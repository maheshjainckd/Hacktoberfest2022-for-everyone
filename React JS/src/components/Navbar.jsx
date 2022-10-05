import React from 'react';
import { NavLink } from 'react-router-dom';

const Navbar = () => {
    return (
        <nav className='navbar' style={{backgroundColor:'#e3f2fd',}}>
            
                <div className='container-fluid'>
                <span className='navbar-brand mb-0 h1 logo'>ToDo trAcK</span>
                
                    <ul className="navbar-nav d-flex flex-row justify-items-center px-3 ">
                        <li className="navbar-item">
                            <NavLink to='/' className='nav-link px-2'>Home</NavLink>
                        </li>
                        <li className="navbar-item">
                            <NavLink to='/create-todo' className='nav-link' style={({isActivate})=>({color: isActivate ? 'green': 'blue'})}>new todo</NavLink>
                        </li>
                    </ul>
                
                    {/* <ul className="navbar-nav d-flex flex-row justify-*items-center px-3 ">
                        <li className="navbar-item">
                            <NavLink to='/' className='nav-NavLink px-2'>Home</NavLink>
                        </li>
                        <li className="navbar-item">
                            <NavLink to='/create-todo' className='nav-NavLink'>new todo</NavLink>
                        </li>
                    </ul> */}
                </div> 
            
        </nav>
    );
};

export default Navbar;