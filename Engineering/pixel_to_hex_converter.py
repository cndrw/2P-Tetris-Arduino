from PIL import Image


class Tile:
    def __init__(self, position, value) -> None:
        self.position = position
        self.value = value
        

img = Image.open("test2.png")

Tiles = []
rows = []

for x in range(img.width):
    row = ""
    for y in range(img.height):
        pixel = img.getpixel((x, y))
        if (pixel[0] == 0):
           row += "1"
        else:
            row += "0"
    rows.append(row)


print(rows)

with open("output.txt", "w", ) as f:
    for r in rows: 
        f.write(r)
        f.write("\n")


