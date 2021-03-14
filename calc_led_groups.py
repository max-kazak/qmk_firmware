back_light = range(88,120)

registers = [0,0,0,0]

# CTRL
all_keys = {
	"numpad": [35, 36, 37, 52, 53, 54, 65, 66, 67, 68, 79],
	"numpad_ops": [38, 39, 55, 56, 51],
	"media": [7, 8, 9, 11, 12, 13, 29],
	"led_control": [14, 15, 16, 31, 32, 33, 48, 49, 50],
	"back_light": range(88, 120),
	"rest": [1, 34, 64, 77, 78, 80, 81, 82, 83, 84, 75, 63, 47, 30, 45, 46, 61, 62, 72, 73, 74, 76, 85, 86, 87] + list(range(17, 29))
}

# ALT
all_keys = {
    "numpad": [17,18,19,32,33,34,46,47,48,49,61],
    "numpad_ops": [31,20,21,35,36,],
    "media": [15,44,58,26],
    "led_control": [23,24,25],
    "back_light": range(68, 107),
    "f_row": range(2,14),
    "rest": [1,16,45,59,60,62,63,64,30,57,65,66,67,53,54,55,56,41,42,43,27,28,29]
}

#Loop through all_keys to do the calculation
for key_group_name, key_group_keys in all_keys.items():
    for led in key_group_keys:
        nled = led -1
        id = nled // 32
        element = nled % 32
        value = 2 ** element
        registers[id] = registers[id] + value

    print('%s .id0 = %s, .id1 = %s, .id2 = %s, .id3 = %s,'%(key_group_name, registers[0], registers[1], registers[2], registers[3]))
    registers = [0,0,0,0]
