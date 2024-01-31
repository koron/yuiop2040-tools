# FM24CL64B (FRAM) sample driver

* Capacity: 8KiB (0000h ~ 1FFFh)

## Pinouts

Num |Name  |Description
---:|------|-------------
0   |A0    |Device select address #0
1   |A1    |Device select address #1
2   |A2    |Device select address #2
3   |VSS   |Ground for device
4   |VDD   |Power supply
5   |WP    |Write protect when tied to VDD
6   |SCL   |I2C Serial clock
7   |SDA   |I2C Serial data/address

`A0~A2` are pulled down internally.

`WP` is pulled down internally.

`VDD` should be 2.7 ~ 3.65V

`SCL` up to 1MHz freq.
Supports legacy timings for 100kHz and 400kHz

> Data is clocked out of the device on the falling edge, and into the device on the rising edge.
> The SCL input also incorporates a Schmitt trigger input for noise immunity.

`SDA`

## START/STOP Condition

* START Condition (S): keep SCL high, and make SDA high to low.
* STOP Condition (P): keep SCL high, and make SDa low to high.

## Slave Device Address

Format: `  1  0  1  0 A2 A1 A0 RW`

`RW`: 1=Read 0=Write

## Memory Operation

*   Write: single byte write と multi bytes write がシーケンシャルに繋がってる。
    Slave adderss, Address MSB, Address LSB, Data bytes x (as you needs)
    
*   Read: two types of read operations

    1. current address read
    2. selective adress read

        Write operationの最初の3バイトを送ったあとに、
        START Conditionを成立させてcurrent address readへ移行する。
