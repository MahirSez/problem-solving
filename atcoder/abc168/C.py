import math

a, b, h, m = map(int, input().split())
ang1 = (h*60 + m)/2
x = (h*60 + m) % 60
ang2 = (6 * x)
# print(ang1 , ang2)
ang = abs( ang1 - ang2 )
ang = min(ang, 360 - ang) * math.pi / 180

ans = a*a + b*b - 2*a*b*math.cos(ang)
print("%.12f" % math.sqrt(ans) )



