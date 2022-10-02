import React from 'react'
import './Home.css'

import Img1 from '../../images/Hero-bg1.png'
import Vector1 from '../../images/vector-1.png'
import MyImg from '../../images/favicon.png'

import { BsFillClockFill, BsCodeSlash, BsFillCupFill } from "react-icons/bs";
import { MdOutlineNightsStay } from "react-icons/md";


// import Wave from './Wave';

function Home() {


    const parallex = {
        backgroundImage: `url(${Img1})`,
        backgroundAttachment: "fixed",
        backgroundPosition: "center",
        backgroundRepeat: "no-repeat",
        backgroundSize: "cover",
    };

    return (
        <>
            <section style={parallex} >
                <div className="container" style={{paddingTop: '5rem', paddingBottom: '5rem'}}>
                    <div className="row">
                        <div className="col-lg-7 col-md-6 col-sm-12">
                            <h1> Hi, <br />I'm Anurag,</h1>

                            <div className="me my-3">
                                <h1>
                                    <span>.</span>
                                    <div className="message">
                                        <div className="word1">entrepreneur</div>
                                        <div className="word2">web developer</div>
                                        <div className="word3">java developer</div>
                                    </div>
                                </h1>
                            </div>

                            <p className='my-3'>Co-Founder and CTO of uncovercampus <br /> Software developer with strong technical skills anchored on extensive engineering coursework and a special focus on Front-end as well as Back-end Development and Database management</p>
                        </div>
                        <div className="col-lg-5 col-md-6 col-sm-12 text-center">
                            <img src={MyImg} alt=""/>
                        </div>
                    </div>
                    {/* <Wave /> */}
                </div>
            </section>
            <section>
                <div className="container py-3">
                    <div className="row">
                        <div className="col-lg-4 col-md-4 col-sm-12">
                            <img src={Vector1} alt="" style={{ height: '22rem' }} />
                        </div>
                        <div className="col-lg-8 col-md-8 col-sm-12">
                            <div className="d-flex flex-wrap justify-content-around my-5 py-5">
                                <div className='text-center'>
                                    <BsFillClockFill className='my-2' fontSize='3rem'/>
                                    <h2>2,000 +</h2>
                                    <h5>Working Hours</h5>
                                </div>
                                <div className='text-center'>
                                    <BsCodeSlash className='my-2' fontSize='3rem'/>
                                    <h2>15,000+</h2>
                                    <h5>Lines Of Code</h5>
                                </div>
                                <div className='text-center'>
                                    <BsFillCupFill className='my-2' fontSize='3rem'/>
                                    <h2>500+</h2>
                                    <h5>Cups of Coffee</h5>
                                </div>
                                <div className='text-center'>
                                    <MdOutlineNightsStay className='my-2' fontSize='3rem'/>
                                    <h2>200+</h2>
                                    <h5>Sleepless Nights</h5>
                                </div>
                            </div>
                        </div>
                    </div>
                    {/* <Wave /> */}
                </div>
            </section>

            {/* <section>
                <Bio />
            </section>
            <section>
                <About />
            </section>
            <section>
                <MyProjects />
            </section> */}
        </>
    )
}

export default Home
