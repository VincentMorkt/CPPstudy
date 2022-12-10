-- расчёт разницы между текущим входящим сигналом и входящим сигналом nTicks + 1 назад

-- функции ввода-вывода
input.getNumber,input.getBool,output.setNumber,output.setBool = IN,IB,ON,OB

-- глобальные переменные, сохраняющие значения между циклами
local n                 -- индекс для управления обращения к массиву
local complete = false  -- маркер завершения заполнения массива
local stream = {}       -- массив, хранящий поток входящих данных
local dif               -- разница между текущим значением, и значением, отстающим на nTicks тиков

function onTick()
    -- ввод значений с входов контроллера
    local nTicks = IN(1)*60 + 1 --ввод длительности анализа сигнала в секундах для расчёта разницы (+1 тик для текущего тика)
    local targetFind = IB(1) --маркер обнаружения цели

    if !targetFind then n,complete,dif = 1,false,0  -- если цель не обнаружена, индекс = 1,расчёт не завершён, разница равна нулю
    else if targetFind then -- иначе если цель обнаружена

        stream[n] = IN(2)   -- элементу массива с индексом n присваивается значение из входящего потока

        if !complete or n == nTicks then dif = stream[n] - stream[1] -- если массив заполнен или индекс максимальный, 
                                                                    -- разница считается между текущим элементом и первым
        else dif = stream[n] - stream[n + 1] end                    -- иначе разница считается между текущим элементом и следующим (максимально далёким)
        n = n + 1                                                   -- инкремент индекса

        if n >= nTicks then n,complete = 1,true end -- если достигнут предел массива, 
        --возвращаемся к началу массива, расчёт завершён (сохраняется до потери цели)
    end
    end
    ON(1, dif) --вывод разницы между текущим входящим сигналом и входящим сигналом nTicks + 1 назад
end


-- 

-- функции ввода-вывода
-- input.getNumber,input.getBool,output.setNumber,output.setBool = IN,IB,ON,OB

function onTick()
    x = IN(1)     -- ввод потока
    xdif = IN(2)  -- ввод разницы потока
    difdif = IN(3)-- ввод разницы разницы потока
    time = IN(4)  -- ввод времени в секундах для расчёта необходимого упреждения
    ON(1, x + xdif * time + difdif * time)  -- поток (текущее положение)
                                        -- + разница потока * время(полёта снаряда) (предсказание положения через время полёта снаряда)
                                        -- + разница разницы потока * время(полёта снаряда) (предсказание изменения предсказания через время полёта снаряда)
end



-- pid controller
local error_prior = 0
local integral_prior = 0
local kp = 0.2
local ki = 0.001
local kd = 0.1
local bias = 0

function onTick()
	setRps = input.getNumber(1)
	getRps = input.getNumber(2)
	
	error = setRps - getRps
	integral = integral_prior+error
	derivative = error-error_prior	
	
	value_out = kp*error+ki*integral+kd*derivative+bias
	
	error_prior = error
	integral_prior = integral
	
	output.setNumber(1,value_out)
end