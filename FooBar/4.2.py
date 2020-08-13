from math import sqrt


def solution(dimensions, your_position, guard_position, distance):
    def gcd(a, b):
        while b:
            a, b = b, a % b

        return a

    def get_distance(p1, p2):
        dx = abs(p1[0] - p2[0])
        dy = abs(p1[1] - p2[1])

        return sqrt(dx**2 + dy**2)

    [w, h] = dimensions
    refs_me = dict()
    refs_guardian = dict()

    c = 0
    while True:
        found = False

        [x1, y1] = your_position
        [x2, y2] = guard_position
        for i in range(c+1):
            j = c - i
            for k in [[1, 1], [1, -1], [-1, 1], [-1, -1]]:
                me_ref = (x1 + 2*i*k[0]*w, y1 + 2*j*k[1]*h)
                guardian_ref = (x2 + 2*i*k[0]*w, y2 + 2*j*k[1]*h)

                dx1 = 2*(w-x1)
                dy1 = 2*(h-y1)
                dx2 = 2*(w-x2)
                dy2 = 2*(h-y2)
                for f in [[1, 0], [0, 1], [1, 1], [0, 0]]:
                    r1 = (me_ref[0] + dx1*f[0], me_ref[1] + dy1*f[1])
                    r2 = (guardian_ref[0] + dx2*f[0],
                          guardian_ref[1] + dy2*f[1])

                    d1 = get_distance(r1, your_position)
                    if (d1 <= distance):
                        found = True
                        refs_me[r1] = d1

                    d2 = get_distance(r2, your_position)
                    if (d2 <= distance):
                        found = True
                        refs_guardian[r2] = d2

        if not found:
            break
        c += 1

    beams_me = dict()
    beams_guardian = dict()

    for r, d in refs_me.items():
        dx = r[0] - your_position[0]
        dy = r[1] - your_position[1]
        if dx == 0 and dy == 0:
            continue
        g = abs(gcd(dx, dy))
        v = (dx/g, dy/g)
        if not beams_me.get(v) or beams_me[v] > d:
            beams_me[v] = d

    for r, d in refs_guardian.items():
        dx = r[0] - your_position[0]
        dy = r[1] - your_position[1]
        g = abs(gcd(dx, dy))
        v = (dx/g, dy/g)
        if not beams_guardian.get(v) or beams_guardian[v] > d:
            beams_guardian[v] = d

    ans = 0
    for b, d in beams_guardian.items():
        if not beams_me.get(b) or beams_me[b] > d:
            ans += 1

    return ans


# dim, yp, gp, dis = [1250, 1250], [150, 150], [185, 100], 10000
# dim, yp, gp, dis = [300, 275], [150, 150], [185, 100], 500
dim, yp, gp, dis = [3, 2], [1, 1], [2, 1], 4

print(solution(dim, yp, gp, dis))
