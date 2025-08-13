#!/usr/bin/env python3
"""
🌸 Create Demo Images for Hand Control Interface
This script creates simple demo images to show how image embedding works.
"""

import os
from PIL import Image, ImageDraw, ImageFont

def create_demo_images():
    """Create simple demo images to showcase the image functionality."""
    
    images_dir = "images"
    os.makedirs(images_dir, exist_ok=True)
    
    # Create a soft purple gradient background
    def create_gradient_background():
        img = Image.new('RGB', (750, 650), '#F8F4FF')
        draw = ImageDraw.Draw(img)
        
        # Create a subtle vertical gradient
        for y in range(650):
            # Fade from light purple to very light purple
            alpha = y / 650
            r = int(248 + (255-248) * alpha)
            g = int(244 + (255-244) * alpha) 
            b = int(255)
            color = (r, g, b)
            draw.line([(0, y), (750, y)], fill=color)
        
        return img
    
    # Create a cute header banner
    def create_header():
        img = Image.new('RGBA', (600, 80), '#E8D5FF')
        draw = ImageDraw.Draw(img)
        
        # Draw a cute border
        draw.rectangle([0, 0, 599, 79], outline='#B794F6', width=3)
        
        # Add some decorative dots
        for i in range(0, 600, 50):
            draw.ellipse([i-3, 10, i+3, 16], fill='#D6BCFA')
            draw.ellipse([i-3, 64, i+3, 70], fill='#D6BCFA')
        
        return img
    
    # Create a simple logo
    def create_logo():
        img = Image.new('RGBA', (48, 48), '#E8D5FF')
        draw = ImageDraw.Draw(img)
        
        # Draw a cute hand symbol
        draw.ellipse([12, 12, 36, 36], fill='#B794F6', outline='#805AD5', width=2)
        draw.text((24, 24), "✋", anchor="mm", fill='white')
        
        return img
    
    # Create decorative elements
    def create_flower():
        img = Image.new('RGBA', (32, 32), (0, 0, 0, 0))  # Transparent
        draw = ImageDraw.Draw(img)
        
        # Simple flower shape
        center = (16, 16)
        for angle in range(0, 360, 72):  # 5 petals
            x = center[0] + 8 * (1 if angle % 144 == 0 else 0.6)
            y = center[1] + 8 * (1 if angle % 144 == 72 else 0.6)
            draw.ellipse([x-4, y-4, x+4, y+4], fill='#E8D5FF')
        
        # Center
        draw.ellipse([center[0]-3, center[1]-3, center[0]+3, center[1]+3], fill='#B794F6')
        
        return img
    
    try:
        # Create and save demo images
        print("🎨 Creating demo images...")
        
        # Background
        bg = create_gradient_background()
        bg.save(os.path.join(images_dir, "background.png"))
        print("✅ Created background.png")
        
        # Header
        header = create_header()
        header.save(os.path.join(images_dir, "header.png"))
        print("✅ Created header.png")
        
        # Logo
        logo = create_logo()
        logo.save(os.path.join(images_dir, "logo.png"))
        print("✅ Created logo.png")
        
        # Decorative flower
        flower = create_flower()
        flower.save(os.path.join(images_dir, "flower.png"))
        print("✅ Created flower.png")
        
        print("\n🌸 Demo images created successfully!")
        print("Run your Hand Control Interface to see them in action!")
        
    except Exception as e:
        print(f"❌ Error creating demo images: {e}")
        print("You can still add your own images manually to the images/ folder")

if __name__ == "__main__":
    create_demo_images()
