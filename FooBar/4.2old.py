from math import sqrt


def solution(dimensions, your_position, guard_position, distance):
    MAX_D = 10000
    w, h = dimensions[0], dimensions[1]

    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    def is_reflection(p1, p2):
        [x1, y1] = p1
        [x2, y2] = p2
        dx1, dy1 = w - x1, h - y1

        ref_x = (x2 - x1) % (2*w) == 0 or (x2 - x1 - 2*dx1) % (2*w) == 0
        ref_y = (y2 - y1) % (2*h) == 0 or (y2 - y1 - 2*dy1) % (2*h) == 0
        if (ref_x and ref_y):
            # print(p1, p2)
            return True
        return False

    to_guardian = dict()
    to_me = dict()
    for a in range(distance+1):
        max_b = int(sqrt(distance**2 - a**2)) + 1
        for b in range(max_b):
            curr_d = sqrt(a**2 + b**2)
            for k in [[1, 1], [1, -1], [-1, 1], [-1, -1]]:
                dx = a*k[0]
                dy = b*k[1]
                i = your_position[0] + dx
                j = your_position[1] + dy
                point = (i, j)

                if (is_reflection(guard_position, point)):
                    g = gcd(a, b)
                    v = (dx/g, dy/g) if g else (dx, dy)
                    prev_d = to_guardian[v] if to_guardian.get(v) else MAX_D
                    to_guardian[v] = min(curr_d, prev_d)
                if (is_reflection(your_position, point)):
                    g = gcd(a, b)
                    v = (dx/g, dy/g) if g else (dx, dy)
                    prev_d = to_me[v] if to_me.get(v) else MAX_D
                    to_me[v] = min(curr_d, prev_d)

    ans = 0
    for k, d in to_guardian.items():
        if not to_me.get(k) or to_me.get(k) > d:
            print(k)
            ans += 1

    return ans


# dim, yp, gp, dis = [120, 1250], [150, 150], [185, 100], 10000
dim, yp, gp, dis = [300, 275], [150, 150], [185, 100], 500

print(solution(dim, yp, gp, dis))
