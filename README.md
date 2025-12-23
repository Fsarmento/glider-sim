# glider-sim
A glider flight simulation cockpit project. Includes 3D printable STL parts, bill of materials, controller code, and assembly instructions.

> [!NOTE]
> This page is still under construction and being updated with more information.

This project was designed to be used with the **Condor 3** glider flight simulator.

## Bill of Materials (BOM)

> [!NOTE]
> The AliExpress links do not have the correct product options pre-selected. Please make sure to select the correct options according to the item description.



### Frame

| Quantity | Type | Size | Length | Description | Shop |
|----------|------|------|--------|-------------|------|
| 1 | Aluminium Profile | 4040 | 900 | main frame | |
| 1 | Aluminium Profile | 4040 | 600 | side frame | |
| 3 | Aluminium Profile | 2040 | 300 | vertial arms | |
| 1 | Aluminium Profile | 2040 | 120 | front panel | |
| 3 | Aluminium Profile | 2020 | 200 | sliders | |
| 1 | Aluminium Profile | 2020 | 300 | joystick | |
| 2 | Aluminium Profile | 2020 | 150 | pedals | |
| 1 | Aluminium Profile | 2080 | 300 | feet rest | |
| 14 | Profile T connectors | 2020 | | Profile Connector Corner Bracket | [Link](https://pt.aliexpress.com/item/1005005600396191.html) |
| 2 | Profile 90 deg connector | 2020-2 L40 | | L connector 2020-2 L40 (sliders base) | [Link](https://pt.aliexpress.com/item/1005004312946435.html) |
| 4 | Profile 90 deg connector | 2020-2 L20 | | L connector 2020-2 L20 (sliders base) | [Link](https://pt.aliexpress.com/item/1005004312946435.html) |
| 1 | Profile 90 deg connector | 2040B-6 | | L connector 2040B-6 (secondary slider) | [Link](https://pt.aliexpress.com/item/1005004312946435.html) |
| 3 | Telescopic Feet | | 16.5CM-28.5CM | Telescopic Feet 16.5CM-28.5CM | [Link](https://pt.aliexpress.com/item/1005007648713847.html) |

### Joystick Base

| Quantity | Type | Size | Length | Description | Shop |
|----------|------|------|--------|-------------|------|
| 4 | Bearings | 10x26x8mm | | Bearings 10x26x8mm (Inside diameter x Outside diameter x Width) | [Link](https://www.aliexpress.com/item/1005007668446060.html) |
| 2 | Shoulder Bolts | D10M8 | 20 | M8x20 Shoulder Bolts (10mm shoulder, 8mm thread) | [Link](https://pt.aliexpress.com/item/1005008615324350.html) |
| 2 | Shoulder Bolts | D10M8 | 10 | M8x10 Shoulder Bolts (10mm shoulder, 8mm thread) | [Link](https://pt.aliexpress.com/item/1005008615324350.html) |
| 8 | Bolts (Option A) | M5 | 10 | M5x10 Bolts to fix springs | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 5 | Bolts | M5 | 14 | M5x14 Bolts | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 10 | Bolts | M5 | 20 | M5x20 Bolts | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 15 | T-slot Nuts | M5 | | M5 T-slot Nuts | [Link](https://pt.aliexpress.com/item/1005007383347166.html) |
| 2 | Magnets | 8x8x8 | | 8mm cube magnets | [Link](https://pt.aliexpress.com/item/1005009224525065.html) |
| 2 | Hall Effect Sensor | | | Hall Effect Sensor SS496A1 | [Link](https://pt.aliexpress.com/item/1005008652267102.html) |
| 4 | Option A: Springs | | 75 | 75x10x1.25mm Springs (Length x Outside Diameter x Wire Diameter) | [Link](https://pt.aliexpress.com/item/1005003939622047.html) |
| 4 | Option B: Oil shock absorber | | 110 | oil shock absorber 110mm | [Link](https://pt.aliexpress.com/item/1005005791841993.html) |
| 4 | Option B: M3-M5 Adapter | M3-M5 | 10 | M3-M5 10mm Thread Adapter Screw Nuts | [Link](https://pt.aliexpress.com/item/1005007436046737.html) |

### Joystick Controller

| Quantity | Type | Size | Length | Description | Shop |
|----------|------|------|--------|-------------|------|
| 4 | M2-M4 Adapter | M2-M4 | 8 | 4pcs M2-M4 8mm Thread Adapter Screw Nuts | [Link](https://pt.aliexpress.com/item/1005007436046737.html) |
| 4 | Flat Bolts | M2 | 10 | 4pcs M2x10 Flat Countersunk Head Bolt | [Link](https://pt.aliexpress.com/item/1005007148309873.html) |
| 1 | Controller ESP32-C3 | | | 1pc ESP32-C3 Supermini | [Link](https://pt.aliexpress.com/item/1005008212278653.html) |
| 4 | Push Button Switch | 6x6x4.1 | | 4pcs Push Button Switch 4x4x4.1 DIP (4x4x4.3 is also ok) | [Link](https://pt.aliexpress.com/item/1005001629177989.html) |
| 1 | 5-way Switch | 10x10x10 | | 1pc 5-way tactile switch 10x10x10 DIP | [Link](https://pt.aliexpress.com/item/4000681560472.html) |

### Rudder Pedals

| Quantity | Type | Size | Length | Description | Shop |
|----------|------|------|--------|-------------|------|
| 3 | Shoulder Bolts | D10M8 | 30 | M8x30 Shoulder Bolts | [Link](https://pt.aliexpress.com/item/1005008615324350.html) |
| 6 | Bearings | 10x26x8mm | | Bearings 10x26x8mm (Inside diameter x Outside diameter x Width) | [Link](https://www.aliexpress.com/item/1005007668446060.html) |
| 14 | Bolts | M5 | 10 | M5x14mm Bolts (Feet Rest) | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 4 | Bolts | M5 | 14 | M5x14mm Bolts (Option A - Springs) | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 16 | Bolts | M5 | 20 | M5x20mm Bolts | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 32 | T-slot Nuts | M5 | | M5 T-slot Nuts | [Link](https://pt.aliexpress.com/item/1005007383347166.html) |
| 6 | T-slot Nuts | M3 | | M3 T-slot Nuts | [Link](https://pt.aliexpress.com/item/1005007383347166.html) |
| 2 | Bolts | M5 | 100 | M5x100mm Bolts | [Link](https://pt.aliexpress.com/item/32969034133.html) |
| 2 | Link Rods | M3 | 110 | Stainless steel link rods with rod ends 110mm | [Link](https://pt.aliexpress.com/item/1005007792947401.html) |
| 2 | M3-M5 Adapter | M3-M5 | 10 | M3-M5 10mm Thread Adapter Screw Nuts (Link rod) | [Link](https://pt.aliexpress.com/item/1005007436046737.html) |
| 6 | Bolts | M3 | 20 | M3x18mm Bolts (link spacer/shock absorber) | [Link](https://pt.aliexpress.com/item/1005009149226092.html) |
| 2 | Bolts | M3 | 16 | M3x16mm Bolts (Shock absorber) | [Link](https://pt.aliexpress.com/item/1005009149226092.html) |
| 2 | Magnets | 8x8x8 | | 8mm cube magnets | [Link](https://pt.aliexpress.com/item/1005009224525065.html) |
| 1 | Hall Effect Sensor | | | Hall Effect Sensor SS496A1 | [Link](https://pt.aliexpress.com/item/1005008652267102.html) |
| 2 | Option A: Springs | | 75 | 75x10x1.25mm Springs (Length x Outside Diameter x Wire Diameter) | [Link](https://pt.aliexpress.com/item/1005003939622047.html) |
| 2 | Option B: Oil shock absorber | | 110 | oil shock absorber 110mm | [Link](https://pt.aliexpress.com/item/4000245803426.html) |


> [!WARNING]
> This BOM is still under development. The following sections are missing:
> - Sliders
> - 6 Button Case
> - Trim
> - Release
> - Chair Holder
> - Controller Box
## Credits

The joystick handle design was adapted from the [OpenVario Remote Stick project](https://www.openvario.org/doku.php?id=projects:remote_00:top), created by the OpenVario community.

The joystick and rudder pedals were adapted from the [Flight-Simulator-Joystick](https://github.com/TomStanton/Flight-Simulator-Joystick) project, developed by Tom Stanton.

## Photos

### Front View
![Front View](photos/front.jpg)

### Back View
![Back View](photos/back.jpg)

### Control Stick
![Control Stick](photos/stick.jpg)

### Rudder Pedals
![Rudder Pedals](photos/rudder.jpg)

### Flaps & Airbrakes
![Flaps & Airbrakes](photos/flaps&airbreaks.jpg)

### Gear & Trim
![Gear & Trim](photos/gear&trim.jpg)
