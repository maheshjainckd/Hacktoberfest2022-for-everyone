import React from 'react'

import './MyProject.css'
import TabPanel from './TabPanel'

function MyProjects() {
    return (
        <>
        <section className='bgimg py-5'>
            <div className='text-center'>
                <h4 style={{color: '#cbb26a'}}>CASE STUDIES</h4>
                <h2>Project Work</h2>
                <TabPanel />
            </div>
        </section>
        </>
    )
}

export default MyProjects
