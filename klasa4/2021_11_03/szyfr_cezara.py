def getSteppedLetter(letter, jump):
    jump %= (ord('Z') - ord('A') + 1)
    temp_letter = chr(ord(letter) + jump)
    if temp_letter > 'Z':
        temp_letter = chr(ord(temp_letter) + ord('A') - ord('Z') - 1)
    return temp_letter

def cesarCipher(text: str, key: int):
    output = ""
    for i in text:
        output += getSteppedLetter(i, key)
    return output

def getSteppedLetterDecode(letter, jump):
    jump %= (ord('Z') - ord('A') + 1)
    temp_letter = chr(ord(letter) - jump)
    if temp_letter < 'A':
        temp_letter = chr(ord(temp_letter) -(ord('A') - ord('Z') - 1))
    return temp_letter

def cesarCipherDecode(text: str, key: int):
    output = ""
    for i in text:
        output += getSteppedLetterDecode(i, key)
    return output

def getJump(a, b):
    diff = ord(b) - ord(a)
    if diff < 0:
        diff += ord('Z') - ord('A') + 1
    return diff

def encodedSuccessfully(text: str, encoded: str):
    diff = getJump(text[0], encoded[0])
    for i, j in zip(text[1:], encoded[1:]):
        if not getJump(i, j) == diff:
            return False
    return True