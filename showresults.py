import apsw
import matplotlib.pyplot as plt
import numpy as np

class Results:

    def __init__(self):
        self.conn = apsw.Connection("output/pioneer.db",
                                    flags=apsw.SQLITE_OPEN_READONLY)
        self.db = self.conn.cursor()
        self.loaded = False

    def load(self):
        self.xs = []
        self.ys = []
        for row in self.db.execute("SELECT scalar, value FROM scalars\
                                    ORDER BY particle_id, scalar;"):
            scalar, value = row

            if scalar == 0:
                self.xs.append(value)
            elif scalar == 1:
                self.ys.append(value)

        self.xs = np.array(self.xs)
        self.ys = np.array(self.ys)
        self.loaded = True


    def plot(self):
        if not self.loaded:
            self.load()

        plt.plot(self.xs, self.ys, ".", alpha=0.3)
        plt.show()


if __name__ == "__main__":
    results = Results()
    results.plot()

