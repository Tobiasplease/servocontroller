#!/usr/bin/env python3
"""
🖐️ Process Hand Image for Header
This script will resize your hand image, remove the background, and prepare it for the header.
"""

from PIL import Image, ImageFilter
import os

def process_hand_image():
    """Process the hand image for use in the header."""
    
    source_path = r"c:\Users\tobia\Pictures\hand.JPG"
    output_path = "header.png"
    
    if not os.path.exists(source_path):
        print(f"❌ Image not found at: {source_path}")
        return False
    
    try:
        print("🖐️ Processing your hand image...")
        
        # Open the image
        img = Image.open(source_path)
        print(f"✅ Loaded image: {img.size[0]}x{img.size[1]}")
        
        # Convert to RGBA for transparency support
        img = img.convert("RGBA")
        
        # Resize to header dimensions (600x80)
        # We'll make it a bit smaller so it fits nicely
        target_width = 120
        target_height = 80
        
        # Calculate aspect ratio to maintain proportions
        aspect_ratio = img.size[0] / img.size[1]
        if aspect_ratio > target_width / target_height:
            # Image is wider, fit to width
            new_width = target_width
            new_height = int(target_width / aspect_ratio)
        else:
            # Image is taller, fit to height
            new_height = target_height
            new_width = int(target_height * aspect_ratio)
        
        img = img.resize((new_width, new_height), Image.Resampling.LANCZOS)
        print(f"✅ Resized to: {new_width}x{new_height}")
        
        # Create a simple background removal
        # This works by making pixels similar to the corner colors transparent
        
        # Get the corner colors (likely background)
        corner_colors = [
            img.getpixel((0, 0)),
            img.getpixel((img.size[0]-1, 0)),
            img.getpixel((0, img.size[1]-1)),
            img.getpixel((img.size[0]-1, img.size[1]-1))
        ]
        
        # Find the most common corner color (likely the background)
        from collections import Counter
        corner_rgb = [(r, g, b) for r, g, b, a in corner_colors]
        most_common_bg = Counter(corner_rgb).most_common(1)[0][0]
        print(f"🎨 Detected background color: {most_common_bg}")
        
        # Make background transparent
        data = img.getdata()
        new_data = []
        
        tolerance = 30  # How similar colors need to be to background
        
        for item in data:
            r, g, b, a = item
            # Check if this pixel is similar to background
            bg_r, bg_g, bg_b = most_common_bg
            
            if (abs(r - bg_r) < tolerance and 
                abs(g - bg_g) < tolerance and 
                abs(b - bg_b) < tolerance):
                # Make it transparent
                new_data.append((r, g, b, 0))
            else:
                # Keep it opaque
                new_data.append((r, g, b, a))
        
        img.putdata(new_data)
        print("✅ Background removed!")
        
        # Create a new image with proper header dimensions
        header_img = Image.new('RGBA', (600, 80), (0, 0, 0, 0))
        
        # Center the hand image in the header
        x_offset = (600 - new_width) // 2
        y_offset = (80 - new_height) // 2
        
        header_img.paste(img, (x_offset, y_offset), img)
        
        # Save the processed image
        header_img.save(output_path)
        print(f"✅ Saved processed hand image as: {output_path}")
        
        return True
        
    except Exception as e:
        print(f"❌ Error processing image: {e}")
        return False

if __name__ == "__main__":
    success = process_hand_image()
    if success:
        print("\n🌸 Your hand image is ready for the header!")
        print("Restart your Hand Control Interface to see it!")
    else:
        print("\n⚠️ Could not process the image. You can try manually editing it.")
