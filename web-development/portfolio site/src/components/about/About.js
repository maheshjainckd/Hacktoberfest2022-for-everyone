import React from 'react'
import TabPanel from './TabPanel'

import Img1 from '../../images/Hero-bg2.jpg'

function About() {
    
    const parallex = {
        backgroundImage: `url(${Img1})`,
        backgroundAttachment: "fixed",
        backgroundPosition: "center",
        backgroundRepeat: "no-repeat",
        backgroundSize: "cover",
    };

    return (
        <>
            <section className='py-5' style={parallex}>
                <div className="container">
                    <h1 className='text-center' style={{fontWeight: 'bolder', color: 'rgb(203, 178, 106)'}}>About Me</h1>
                    <div className='container'>
                        <TabPanel />
                    </div>
                </div>
            </section>
        </>
    )
}

export default About
