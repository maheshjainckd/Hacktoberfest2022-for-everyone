import React from 'react'

import './Navbar.css';

import Img1 from '../../images/Hero-bg1.png'

function Navbar(props) {

    // const navigate = useNavigate();
    // const smoothDirect = () => {
    //     window.scroll({
    //         top: 0,
    //         left: 0,
    //         behavior: "smooth",
    //     });
    // }

    const parallex = {
        backgroundImage: `url(${Img1})`,
        backgroundAttachment: "fixed",
        backgroundPosition: "center",
        backgroundRepeat: "no-repeat",
        backgroundSize: "cover",
    };

    return (
        <>
            <section style={parallex}>
                <div className="container">
                    <nav className="navbar navbar-expand-lg py-4 head">
                        <div className="container-fluid">
                            <a className="navbar-brand mx-5" style={{ color: 'whitesmoke' }} href="/">Anurag Kumar</a>
                            <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                                <span className="navbar-toggler-icon"></span>
                            </button>
                            <div className="collapse navbar-collapse" id="navbarSupportedContent">
                                <ul className="navbar-nav mx-auto mb-lg-0">
                                    <li className="nav-item">
                                        <a className="nav-link active" aria-current="page" style={{ color: 'whitesmoke' }} href='/' >About Me</a>
                                    </li>
                                    <li className="nav-item">
                                        <a className="nav-link" style={{ color: 'whitesmoke' }} href='/' >My Bio</a>
                                    </li>
                                    <li className="nav-item">
                                        <a className="nav-link" style={{ color: 'whitesmoke' }} href='/' >Contact Me</a>
                                    </li>
                                    <li className="nav-item">
                                        <a className="nav-link" style={{ color: 'whitesmoke' }} href='/' >My Projects</a>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </nav>
                </div>
            </section>
        </>
    )
}

export default Navbar
