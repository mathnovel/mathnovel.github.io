---
title: "Detecting Missing Components in Electronic Parts Using Deep Learning – How to Rapidly Collect Large Batches of Training Images"
date: 2025-11-11 12:00:00
categories:
  - tech
  - AI
tags:
  - DL
  - RL
layout: single
author_profile: true
excerpt: "image capture for DL"
header:
  overlay_color: "#333333"
  overlay_filter: 0.5
---

# Missing Components in Factory-Produced Switch Buttons

A properly assembled switch button produced by the factory looks like this:

![Properly Assembled Switch Button](/assets/img/65.png)

The part highlighted in yellow is a small component manually inserted by an operator:

![Component Highlighted](/assets/img/66.png)

Two main issues commonly arise during this manual insertion process:

## 1. Missed Insertion: The "Invisible Defect" Caused by Human Fatigue

On low-volume, high-mix production lines, switches or connectors with tiny metal contacts are often hand-inserted into their housings by operators. This leads to missed insertions due to:

- Extremely small contact size (often <2mm) and color similar to the housing;
- Insufficient or glare-prone lighting at the workstation;
- Operator fatigue from repetitive tasks, reducing attention over time.

This frequently results in situations where the operator *believes* the part was inserted—but it actually wasn’t.

Even more problematic: once the housing snap-fit is closed, there’s **no external indication** of the missing internal component. The product passes visual inspection but fails later in the end device.

## 2. Incomplete Insertion: “Looks Good” But Not Securely Fixed

Even when the operator performs the insertion action, the contact may not be fully seated due to:

- Insufficient insertion force, preventing the contact from snapping into its retention slot;
- Slight housing deformation obstructing proper placement;
- Inconsistent handling techniques (e.g., angled or off-center insertion).

In such cases, the contact is only temporarily held by friction and may fall out during subsequent handling, vibration, or packaging.

The resulting product appears intact and feels normal—but lacks functionality—becoming a hidden “latent defect.”

An example of a defective component missing this part is shown below:

![Defective Component](/assets/img/67.png)

**Therefore, performing integrity inspection before final packaging is absolutely essential.**

---

# Approach: Use Deep Learning to Detect Completeness of Switch Buttons

If we adopt deep learning, the very first step is image acquisition.

## Image Acquisition Method 1: Manual Capture Using Smartphones

1. **Uncontrolled shooting angles → biased model learning**  
   Smartphone photos vary in angle, height, and distance due to human handling.  
   Defects (e.g., missing internal contacts) are often visible only from specific viewpoints. Missing those angles means the model will never learn to detect them.  
   Result: imbalanced training data and poor model generalization.

2. **Unstable lighting → noise interference**  
   Natural or indoor lighting changes with time, weather, and position.  
   Auto-exposure on phones causes significant brightness variations for the same object.  
   The AI may misinterpret lighting changes as structural defects, drastically increasing false alarms.

3. **Cluttered backgrounds → feature extraction interference**  
   Desks, fingers, and random objects often appear in the frame.  
   The model wastes capacity learning irrelevant background features instead of focusing on the target component.  
   Requires extra preprocessing like cropping or segmentation, adding cost and complexity.

4. **Extremely low efficiency + fatigue → insufficient data volume**  
   Capturing 100 samples requires repeated positioning, focusing, and tapping—taking over 30 minutes.  
   Quality further degrades with fatigue (blur, shake, repetitive angles).  
   Yet deep learning typically demands **thousands to tens of thousands** of high-quality images—nearly impossible to achieve manually.

5. **No data standardization → non-reproducible and hard to iterate**  
   Filenames are arbitrary (e.g., `IMG_1234.jpg`).  
   No metadata about angle, timestamp, or device.  
   Want to add more data later or compare model performance? You simply can’t align the datasets!

> **“Garbage in, garbage out.”** No matter how powerful your AI model is, it depends entirely on high-quality training data.

## Image Acquisition Method 2: Use IEO Tech’s Smart Photo Capture Station – IEO-SPC

### Why Our Rotating Imaging Platform Is the Ideal Partner for AI-Based Inspection

### 1 🔄 360° Automatic Rotation + Multi-Angle Imaging  
Place the part once, and the system automatically captures multiple high-resolution images from different angles.  
It reveals side views, bottom surfaces, and internal cavities that are hard for the human eye to see.  
Outputs a standardized dataset: each image includes angle labels, enabling the model to learn spatial relationships effectively.

### 2 💡 Uniform Illumination & Clean Background  
Built-in ring LED lighting eliminates shadows that could obscure critical features.  
Optional white or black background plates enhance object contour visibility.  
Consistent image quality reduces misclassifications caused by lighting variations.

### 3 🤖 Purpose-Built High-Quality Training Data for Deep Learning  
Eliminates the need for repetitive manual positioning—saving up to **90% of data collection time**.

### A Single Shot Captures Multiple Angles

The IEO-SPC Smart Photo Capture Station acquires multi-angle images in one go:

![IEO-SPC Example](/assets/img/68.png)

Defective switch buttons can be easily captured from multiple perspectives, providing rich, diverse data for model training:

![Defective Switch Buttons](/assets/img/69.png)