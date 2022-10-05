import React from 'react';
import { Link } from 'react-router-dom';

const NotFound = () => {
    return (
        <div className='container text-center mt-5'>
            <div className='row align-tems-center'>
                <div className="col">
                    <h1>Page Not Found</h1>
                    <p>Go <Link to='/'> to home page</Link> </p>
                </div>
            </div>
        </div>
    );
};

export default NotFound;