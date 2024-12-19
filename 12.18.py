import docx


def read_word_document(file_path):
    doc = docx.Document(file_path)
    paragraphs_text = []
    for paragraph in doc.paragraphs:
        paragraphs_text.append(paragraph.text)
    return paragraphs_text

def is_abcc(word):
    if len(word) == 4:
        return word[0]!= word[1] and word[2] == word[3]
    return False

def find_abcc_words_in_paragraphs(paragraphs):
    abcc_words = []
    for paragraph in paragraphs:
        words = paragraph.split()
        for word in words:
            if is_abcc(word):
                abcc_words.append(word)
    return abcc_words

file_path = "your_document.docx"
paragraphs = read_word_document(file_path)
abcc_words = find_abcc_words_in_paragraphs(paragraphs)
print(abcc_words)
