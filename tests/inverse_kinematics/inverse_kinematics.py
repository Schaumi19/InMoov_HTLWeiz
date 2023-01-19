import tinyik
import numpy as np

"""
arm = tinyik.Actuator(['z', [1., 0., 0.], 'z', [1., 0., 0.]])
print(arm.angles)
print(arm.ee)
tinyik.visualize(arm)

arm.angles = [np.pi / 6, np.pi / 3]  # or np.deg2rad([30, 60])
print(arm.ee)
tinyik.visualize(arm)

arm.ee = [2 / np.sqrt(2), 2 / np.sqrt(2), 0.]
print(arm.angles)
np.round(np.rad2deg(arm.angles))
tinyik.visualize(arm)

"""
"""
leg = tinyik.Actuator([[0, .0, 5], 'z',[0, .0, 0.2], 'y', [0, .0, 4], [2, 0, .0], 'x', [0, 0.2, 0], 'y', [0, 2, .0], 'x', [0, 2, .0]])
leg.angles = np.deg2rad([0, 0,-90,0,90])
"""

leg = tinyik.Actuator([[0, .0, 1.97], [1.52, 0, .0], 'x', [0, 0.62, 0], 'y', [0, 2.82, .0], 'x', [0, 3.78, .0]])
leg.angles = np.deg2rad([-90,0,90])

tinyik.visualize(leg)

#tinyik.visualize(leg, target=[.8, .9, 5])
    
for x in np.arange(-0.5,5,0.5):
    for y in np.arange(0.5,3.5,0.5):
        for z in np.arange(-1,6,0.5):
            print(str(x)+"|"+str(y)+"|"+str(z))
            tinyik.visualize(leg, target=[x, y, z])
            leg.angles = np.deg2rad([-90,0,90])
            
