from PIL import Image
from enum import Enum
import json

json_file = "gameData.json"

class Color(Enum):
    BLACK = 0
    WHITE = 1
    RED = 2
    GREEN = 3
    BLUE = 4


def getColor(rgba):
    if (rgba[0] == rgba[1] == rgba[2] == 255):
        return 1
    elif (rgba[0] == 255 and rgba[1] == rgba[2] == 0):
        return 2
    elif (rgba[1] == 255 and rgba[0] == rgba[2] == 0):
        return 3
    elif (rgba[2] == 255 and rgba[0] == rgba[1] == 0):
        return 4
    else:
        return 0
        
    
# Open the image file
img = Image.open('maze1.png')

# Get the height and width of the image file
width = img.size[0] # TODO: check to make sure these aren't switched
height = img.size[1]


pixelArray = img.load()

# Iterate through each pixel and store it to the dictionary
gameData = {
    "start" : { },
    "stop" : { },
    "field" : { }
}


field = []
for x in range(width):
    col = []
    for y in range(height):
        color = getColor(pixelArray[x, y])
        col.append(color)
        
        if (color == 2):
            gameData["stop"] = [x, y]
        if (color == 3):
            gameData["start"] = [x, y]
    
    field.append(col)

gameData["field"] = field
    

# Package the dictionary data as a json-formatted string
#json_string = json.dumps(gameData, indent = 4)
json_string = json.dumps(gameData)

# Write the json-formatted string to our json file
with open(json_file, 'w') as f:
    f.write(json_string)
