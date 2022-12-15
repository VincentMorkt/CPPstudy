input.setNumber = InNum

local battlemode = {'on','off','reload'}
local controlemode = {'hand','lookf','loocth'}
local turretmode = {'full','help','none'}

function ontick()
    laser_dist = InNum()
    
    left_r = InNum()
    up_d = InNum()

    look_x = InNum()
    look_y = InNum()

    rad_dist = InNum()
    rad_x = InNum()
    rad_y = InNum()






    slider_speed = 0
    base_rot_speed = 0
    rad_elev = 0
    tur_azim = 0
    tur_elev = 0
end
