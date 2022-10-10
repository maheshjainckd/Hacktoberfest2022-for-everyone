import os
import re
import string
from Sastrawi.StopWordRemover.StopWordRemoverFactory import StopWordRemoverFactory
from nltk.tokenize import word_tokenize 
from Sastrawi.Stemmer.StemmerFactory import StemmerFactory
from sklearn.feature_extraction.text import CountVectorizer
import pandas as pd

files = []

for dirname, _, filenames in os.walk('documents'):
  for filename in filenames:
    files.append(os.path.join(dirname, filename))

corpus = []
for fname in files:
  with open(fname , "r") as file:
    text = file.read()
    corpus.append(text)

corpus_lower = []

for c in corpus:
  corpus_lower.append(c.lower())

corpus_removed_number = []

for c in corpus_lower:
  corpus_removed_number.append(re.sub(r"\d+", "", c))

corpus_removed_punc = []

for c in corpus_removed_number:
  corpus_removed_punc.append(c.translate(str.maketrans("","",string.punctuation)))

corpus_removed_whitespaces = []

for c in corpus_removed_punc:
  corpus_removed_whitespaces.append(c.strip())

factory = StopWordRemoverFactory()
stopword = factory.create_stop_word_remover()

corpus_removed_stop_words = []

for c in corpus_removed_whitespaces:
  corpus_removed_stop_words.append(stopword.remove(c))

factory = StemmerFactory()
stemmer = factory.create_stemmer()

corpus_stemming = []

for c in corpus_removed_stop_words:
  corpus_stemming.append(stemmer.stem(c))

inal_corpus = corpus_stemming

vectorizer = CountVectorizer() 
X = vectorizer.fit_transform(final_corpus)

df = pd.DataFrame(X.toarray(), columns=vectorizer.get_feature_names_out())
books_names = [book.split('/')[-1] for book in files]
df['book'] = books_names
df = df.set_index('book')