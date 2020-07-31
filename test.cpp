get_F = (unsigned int)recv[1] + (unsigned int)recv[2]*256;
get_S = (unsigned int)recv[3] + (unsigned int)recv[4]*256; 
if(get_F==0)
{
    sp=get_S;
    sp=sp-1500;
}
else
{
    angle=get_F;
    angle=angle-1500;
    Judge_Status=get_S;
}

if(avoid_label==0%% stop_label==0)
 {
    if(Judge_Status==2 or sp==0)//识别到了红灯或停车
    {
        speed(0,0);
    }
    else
    {     
        if(Judge_Status==0)
        {
            speed(sp-(angle)*0.2,sp+(angle)*0.2);
        }
        if(Judge_Status==1)
        {                 
            speed(sp-(angle)*0.2,sp+(angle)*0.2);
        }
        if(Judge_Status==8)
        {
            stop_label=1;
        }
        if(Judge_Status==7)
        {         
            avoid_label=1;    
        }
    }
}

R_pre_err = R_cur_err;
R_cur_cnt = Right_cnt;
R_cur_err = sp_r*2.98 - R_cur_cnt;
R_err_sum += R_cur_err;
R_dt_err = R_cur_err - R_pre_err;

pwm_send.right += (R_cur_err * KP) + (R_err_sum * KI) + (R_dt_err * KD);

if(pwm_send.right > 255)
{
    pwm_send.right = 255;
}
else if(pwm_send.right < 0)
{
    pwm_send.right = 0;
}
L_pre_err = L_cur_err;
L_cur_cnt = Left_cnt;
L_cur_err = sp_l*2.98 - L_cur_cnt;
L_err_sum += L_cur_err;
L_dt_err = L_cur_err - L_pre_err;
    
pwm_send.left += (L_cur_err * KP) + (L_err_sum * KI) + (L_dt_err * KD);

if(pwm_send.left > 255)
{
    pwm_send.left = 255;
｝
else if(pwm_send.left < 0)
{
    pwm_send.left = 0;
}
