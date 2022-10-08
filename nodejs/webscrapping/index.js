const express = require('express');
const cors = require('cors');
const axios = require('axios');
const cheerio = require('cheerio');

const app = express();

const port = process.env.PORT || 5000;

app.use(cors());
app.use(express.json());

async function start() {
  const { data } = await axios('https://dps.psx.com.pk/eligible-scrips');

  const $ = cheerio.load(data);

  const final = [];

  $('tr').each((i, item) => {
    let aar = {};

    $(item)
      .children()
      .each((i, item) => {
        const data = $(item).text();

        aar = { ...aar, [i == 0 ? 'Symbol' : 'Name']: data };
      });

    final.push(aar);
  });

  return final.sort();
}

app.get('/', async (req, res) => {
  try {
    const data = await start();

    res.status(200).json({ data });
  } catch (e) {
    res.status(501).json({ data: [], error: e.message });
  }
});

app.listen(port, (err) => console.log(`Port running ${port}`));
