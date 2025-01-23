import random

num_rochas = 10001

minerais = [
    "Aquavitae Terranita",
    "Ferrolita Aquavitae",
    "Ferrolita Aquavitae",
    "Terranita Solarium",
    "Terranita Solarium",
    "Terranita Solarium",
    "Ferrolita",
    "Terranita Ferrolita",
    "Calaris Aquavitae",
    "Aquavitae Calaris Ferrolita"
]

with open("rochas_10000.txt", "w") as f:
    f.write(str(num_rochas) + "\n")
    for i in range(num_rochas, 1, -1):
        lat = random.uniform(-90, 90)
        lon = random.uniform(-180, 180)
        peso = i
        minerais_linha = minerais[i % len(minerais)]
        f.write(f"{lat:.6f} {lon:.6f} {peso} {minerais_linha}\n")