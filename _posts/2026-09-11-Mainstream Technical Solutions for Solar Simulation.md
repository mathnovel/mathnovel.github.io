---
title: "Mainstream Technical Solutions for Solar Simulation"
date: 2026-09-11 00:00:00  # 改为当前或过去时间！
categories:
  - Solar light simulation
  - Testing
tags:
  - Solar light simulation
layout: single
author_profile: true
excerpt: "Solar light simulation"
header:
  overlay_color: "#333333"
  overlay_filter: 0.5
---



Xenon lamp solutions, metal halide lamps, LED array solutions, and plasma lamp solutions

>IEO (AiYiOu)

+ Three commercially mature mainstream solutions: xenon lamp, metal halide lamp, and LED array;
+ The plasma lamp solution, which has only begun to be explored in recent years and is still in the validation stage.


------------------

# 1 Xenon Lamp Solution (Most Widely Used in Traditional Polycrystalline Silicon PV)

The xenon lamp solution is the absolute mainstream approach for polycrystalline silicon photovoltaic cells and packaged modules—from laboratory R&D, process verification, to mass production quality inspection and authoritative certification. It is also the standardized light source technology with optimal adaptability accumulated over decades of development in the crystalline silicon photovoltaic industry. The core reason is that the photoelectric response characteristics of polycrystalline silicon materials, mass production testing requirements, and packaged module inspection standards highly align with the spectral characteristics, beam characteristics, and operating modes of calibrated xenon lamps—a traditional photovoltaic benchmark solution that LED, metal halide, and plasma lamps cannot replace.

## 1.1 Simulation Principle of the Xenon Lamp Solution

<img src= "/assets/img/100/1.jpg" />


Xenon lamps produce light through high-pressure short-arc xenon gas discharge. The light emitted covers a continuous spectrum from ultraviolet at 300nm, through visible light, all the way to near-infrared at 2500nm. After pairing with optical filters, the spectral continuity and matching degree are excellent.

However, simply emitting light is not enough. To reach industrial-grade usage standards, three components are roughly needed:
+ Light source emission
+ Spectral correction mechanism
+ Optical path homogenization output

In terms of physical structure, see the illustration below
<img src= "/assets/img/100/1.png" />


Therefore, solar simulation equipment based on xenon lamps has a somewhat distinctive appearance
<img src= "/assets/img/100/1.jpeg" />
>Image from www.gauage.com/





## 1.2 Advantages of the Xenon Lamp Solution

1. **Best spectral continuity**
From ultraviolet at 300nm, through visible light, to near-infrared at 2500nm, it is a continuous spectrum without the discrete peaks of LEDs. After pairing with AM1.5 filters, AAA-grade spectral matching can be achieved.
1. **Naturally sufficient UV band**
The xenon lamp itself outputs strong UV-A and UV-B, requiring no additional UV light source—suitable for photoaging and material weathering tests.
1. **Easy to scale up in power and area**
A single lamp can reach 1-6kW, and multi-lamp arrays can achieve square-meter-level irradiation area, meeting module-level PV testing requirements.
1. **Spectral variation with output power is relatively small**
Within the operating range, changing the output intensity results in minimal change to the spectral shape.

## 1.3 Disadvantages of the Xenon Lamp Solution

1. **Short bulb lifespan, high consumable costs**
Typically 500-1200 hours; high-power water-cooled xenon lamps may last only a few hundred hours. After bulb aging, spectral drift and beam shift occur, requiring periodic bulb replacement and recalibration.
2. **Huge heat generation, extremely high cooling demands**
Over 80% of energy from high-power xenon lamps becomes heat; high-power models require water cooling plus forced ventilation, resulting in large equipment size.
3. **Cannot be switched on/off instantaneously**
Requires preheating; after extinguishing, it must cool before restarting, not supporting fast strobe or transient switching outside pulse mode.
4. **Spectrum is not independently adjustable**
Can only be adjusted brighter or dimmer as a whole; cannot independently enhance or weaken specific bands such as UV or IR, and cannot simulate spectral changes of dawn, dusk, or cloudy conditions.
5. **Ozone generation**
Short-wave UV ionizes air to produce ozone; equipment requires ventilation. UV output attenuates after the quartz bulb envelope ages.
6. **Complex power supply**: Requires dedicated xenon lamp DC stabilized power supply, with high-voltage ignition for startup.

>Conclusion: Powerful, but also expensive and complex

-------

# 2  Metal Halide Lamp Solution

<img src= "/assets/img/100/3.jpg" />

## 2.1  Light Emission Principle of the Metal Halide Lamp Solution

The metal halide lamp (MH lamp) solar simulator is a gas-discharge light source. The core principle is **mercury vapor arc discharge + metal halide dissociation emission + optical filter spectral correction**. It relies on the superposition of characteristic spectral lines from various metal atoms to form a composite spectrum close to sunlight, then performs filter shaping for photovoltaic device light simulation testing.

The lamp tube is filled with mercury, inert gas (such as argon), and various metal halides (indium iodide, thallium iodide, sodium iodide, etc.). During initial ignition, the ballast provides high voltage to break down the gas inside the tube, first forming argon discharge; as the tube heats up, liquid mercury evaporates to form mercury vapor, establishing mercury arc discharge and producing the foundational blue-white line spectrum.

The arc center temperature can reach thousands of K. The high temperature causes metal halides near the tube wall to evaporate and diffuse into the high-temperature arc zone, where they dissociate: metal halide molecules decompose into **metal atoms + halogen atoms**.

The dissociated metal atoms are excited by high-energy electrons in the arc, and electron transitions release photons, each emitting characteristic spectral lines at corresponding wavelengths (indium, thallium, sodium contributing to blue, green, yellow, red bands respectively).

Different metal halide formulations determine the strength of each band's spectral lines. Mercury itself provides UV and blue bands, while added metal elements fill in the spectral lines of various visible light colors. **A large number of line spectra superimpose to form an approximately continuous composite spectrum**.

>
> Note: It is essentially still a superposition of line spectra, not the true continuous plasma spectrum of xenon lamps. In some bands, spectral gaps or peaks exist, and there is a noticeable gap between the native spectrum and the AM1.5 standard solar spectrum.

When metal atoms diffuse to the cooler tube wall region, they recombine with halogen atoms back into metal halides.

## 2.2  Advantages of the Metal Halide Lamp Solution

1. **Very smooth and continuous IR spectrum**
> 700-2500nm near-mid IR continuous blackbody spectrum, IR portion is very close to sunlight.

1. **Extremely low light source cost**, cheap bulbs, simple power supply.
2. Color temperature is adjustable by changing operating current, maintaining continuous blackbody spectral shape.
3. No ozone generation.


## 2.3  Disadvantages

1. **Native spectrum has almost no UV (300-400nm missing)**
Must add an external UV light source to supplement UV. After supplementation, UV and visible/IR are two independent light sources, **making it very difficult to achieve full-field beam uniformity matching**—this is the biggest pain point of halogen solutions.
2. **Working color temperature is low**
Typically 2800-3200K under rated operation; to simulate 5500K sunlight, filters must heavily cut visible and IR light, causing luminous efficiency to plummet and massive energy waste.
3. **Extremely intense heat generation**
The vast majority of electrical energy is converted to IR thermal radiation. Samples are noticeably heated, producing **thermal interference effects**—making it impossible to distinguish whether effects are from light or heat in photochemical experiments.
4. **Medium lifespan**: several hundred to 2000 hours; higher current means shorter lifespan.
5. **Significant spectral drift**: voltage fluctuations and filament aging cause synchronous drift of color temperature and spectrum; requires frequent calibration.
6. **Cannot achieve AAA-grade spectral matching**, only suitable for simple simulation, **cannot be used for PV metrology calibration**.

>
> Applicable: Low-cost light boxes, IR-focused testing scenarios; often combined with LED: halogen for IR, multi-channel LED for UV-VIS, compensating for each other's shortcomings.



-------

# 3 LED Array Solution

The concept of LED array solar simulation was first proposed in 2003, with the first prototype completed by Tokyo University of Agriculture and Technology. 2003-2010 was the laboratory prototype exploration phase. Limited by LED luminous efficiency and insufficient available wavelengths, spectral matching was limited, used only for basic cell testing research without commercialized products. After 2012, with advancements in high-power, multi-band LED device technology, multi-channel independent dimming and spectral fitting algorithms rapidly matured. In 2017-2018, commercialized equipment was officially launched to market. After 2020, driven by the research boom in perovskite and tandem photovoltaic cells, LED array solutions rapidly gained popularity thanks to their unique advantages of low thermal load, programmable spectrum, and dynamic adjustability—becoming the preferred solution for laboratory performance testing of new photovoltaic devices.


## 3.1 Light Emission Principle

<img src="/assets/img/100/4.jpg" />

A single LED bead is very small in size: external dimensions **3.5 mm × 3.5 mm, thickness approximately 1.8~2.3 mm**

Each LED bead, after production, has the ability to emit different spectra at specified voltages:

<img src="/assets/img/100/5.jpg" />

>Image from: https://www.h-cled.com/hangyedongtai/4144.html

Because LED beads are so small, we can simulate the required spectrum through combinations of various LED beads:

## 3.1.1 LED Array Composed of Different Spectral LED Beads
<img src="/assets/img/100/6.jpg" />

>Image from www.ieeoo.com, IEO (AiYiOu) Technology

## 3.1.2 Multi-Channel Power Supply Paired with LED Array

Having an LED array is not enough. Different LED beads require different power supplies. Even the same type of LED bead emits different spectra at different voltages. Therefore, a multi-channel power supply module is needed to supply different power to different LEDs.

This module is shown below. Its capability is to supply different power to different LEDs on the LED array:

<img src="/assets/img/100/7.jpg" />

>Image from www.ieeoo.com, IEO (AiYiOu) Technology


## 3.1.3 Light Emission Effect of LED Array + Multi-Channel Power Module

Through these two modules, different spectral simulations and illuminance adjustments can be achieved. It can produce full-spectrum, UV-only, or all-white light, dynamically adjusting the spectrum as needed.

<img src="/assets/img/100/23.jpg" />

<img src="/assets/img/100/24.jpg" />

>Same equipment, different spectra and illuminance achievable through power supply adjustment, www.ieeoo.com, IEO (AiYiOu) Technology


## 3.1.4 Dynamic Illuminance and Spectrum Adjustment - Measured:

<div style="position:relative; width:100%; max-width:320px; aspect-ratio:9/16; margin:10px auto;">
<iframe style="position:absolute; top:0; left:0; width:100%; height:100%; border:none;"
  src="https://www.youtube.com/embed/86SWFpj072M"
  title="YouTube Shorts"
  allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
  allowfullscreen>
</iframe>
</div>



## 3.2 Advantages of the LED Array Solution

1. Excellent programmability and dynamic spectrum simulation: Through independent control of multi-channel LEDs in different bands (such as UV, visible, near-IR, etc.), not only can it achieve high-precision fitting to standard solar spectra (such as AM1.5G), but it can also simulate real-time dynamic lighting changes of an actual day at any time via software programming (e.g., one-click switching between morning, noon, and evening spectral and intensity curves)—something traditional mechanical filters fundamentally cannot do.
2. Ultra-long lifespan and "zero" consumables: Traditional xenon lamps typically last only about 1,000 hours, while industrial-grade LED arrays typically last 20,000 to 50,000+ hours. This means that after purchase, customers almost never need to frequently and expensively replace lamps like before, dramatically reducing long-term maintenance costs.
3. True "cold light source" with extremely low thermal radiation: Luminous efficiency is far higher than traditional thermal light sources, with most electrical energy converted to light rather than IR heat. It does not produce intense thermal radiation to bake samples like xenon or halogen lamps, completely eliminating thermal effect interference on precision photovoltaic, material aging, or biological experiments—and eliminating bulky, noisy water-cooling units.
4. Instant on/off and stepless dimming: Traditional xenon lamps require preheating and high-voltage triggering, with switching limited by lifespan; LED arrays can light up and turn off in milliseconds, achieving stepless, smooth light intensity adjustment across the full range with extremely stable output.
5. Safe and environmentally friendly, no high-voltage or ozone hazards: Uses low-voltage DC drive, without the high-pressure burst risk of traditional xenon lamps during operation, and produces no ozone—more friendly to laboratory safety and environment. Because it only requires ordinary mains power, with low environmental requirements, solar simulation can be achieved at very low cost.
6. IoT integration capabilities: Power adjustment, sensor readings, temperature monitoring—all can be implemented through programming. This mode is far more aligned with modern automation characteristics than previous approaches.


## 3.3 Disadvantages of the LED Array Solution

1. Spectrum is discrete, spectral fitting is complex: LEDs are narrowband single-color light-emitting devices. The array is a **composite spectrum formed by superposition of multiple discrete-wavelength LEDs**, not the continuous plasma spectrum of xenon lamps. Multiple wavelengths of beads must be selected and combined to fit the matching spectrum. Deep-UV LEDs have low electro-optical conversion efficiency and weak output, making UV band supplementation costly.
2. Large-area uniform beam is difficult to achieve: Beads are spatially discrete point sources, and different wavelength beads require interleaved mixing. Small beams (≤50×50mm) can easily achieve A+/AAA; **when the beam expands to module level (e.g., 1600mm×1000mm), spatial spectral uniformity is hard to guarantee**: local areas may have excessive or insufficient intensity in certain bands, leading to inconsistent spectral distribution across the sample plane.
3. Requires additional programming to drive, complex channel control: Different LED combinations are needed to fit the appropriate spectrum, requiring power supply control capabilities rather than simply installing and using directly.


-------

# 4 Plasma Lamp Solution

The principle of the plasma lamp solution is microwave-excited electrodeless plasma light emission, without electrodes—distinguishing it from xenon lamps which rely on electrode arc discharge.
This solution has only begun to be explored in recent years, and currently has no solid data available.
What is known is that the entire solution is similar to the xenon lamp solution, with relatively high lamp prices, and reportedly longer lifespan than xenon lamps.
<img src="/assets/img/100/28.jpg" />
<img src="/assets/img/100/29.jpg" />
