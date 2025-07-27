from PIL import Image


class Tile:
    def __init__(self, position, value) -> None:
        self.position = position
        self.value = value
        


img = Image.open("images/Settingsmenü.png")

Tiles = []
rows = []

for y in range(img.height):
    row = ""
    for x in range(img.width):
        pixel = img.getpixel((x, y))
        if (pixel[3] == 0):
           row += "0"
        else:
            row += "1"
    rows.append(row)

with open("output.txt", "w", ) as f:
    for r in rows: 
        f.write("0b")
        f.write(r)
        f.write(",\n")


