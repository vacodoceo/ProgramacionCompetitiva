from math import sqrt


def solution(dimensions, your_position, guard_position, distance):
    w, h = dimensions[0], dimensions[1]

    cc = 0

    def gcd(a, b):
        count = 0
        while b:
            count += 1
            a, b = b, a % b
        return a, count

    def is_reflection(p1, p2):
        [x1, y1] = p1
        [x2, y2] = p2
        dx1, dy1 = w - x1, h - y1

        ref_x = (x2 - x1) % (2*w) == 0 or (x2 - x1 - 2*dx1) % (2*w) == 0
        if not ref_x:
            return False
        return (y2 - y1) % (2*h) == 0 or (y2 - y1 - 2*dy1) % (2*h) == 0

    ans = 0

    for a in range(2*w+1):
        dx = a-w
        for b in range(2*h+1):
            dy = b-h
            g, count = gcd(abs(dx), abs(dy))
            cc = max(count, cc)
            if (g > 1):
                continue

            t = 1
            mod = sqrt(dx**2 + dy**2)
            while (mod*t <= distance):
                i = your_position[0] + dx*t
                j = your_position[1] + dy*t
                point = (i, j)

                if (is_reflection(guard_position, point)):
                    ans += 1
                    break
                if (is_reflection(your_position, point)):
                    break
                t += 1
    print(cc)
    return ans


dim, yp, gp, dis = [1250, 1250], [150, 150], [185, 100], 10000
# dim, yp, gp, dis = [300, 275], [150, 150], [185, 100], 500
# dim, yp, gp, dis = [3, 2], [1, 1], [2, 1], 10000

print(solution(dim, yp, gp, dis))
