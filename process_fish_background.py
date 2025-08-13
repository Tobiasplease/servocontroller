#!/usr/bin/env python3
"""
🐟 Process Fish Background Image
This script will resize your fish image to fit as a background for the interface.
"""

from PIL import Image
import os

def process_fish_background():
    """Process the fish image for use as background."""
    
    # Try different possible names for the fish image
    possible_names = [
        "fish_scene.jpg", "fish.jpg", "water.jpg", "background_fish.jpg",
        "fish_scene.png", "fish.png", "water.png", "background_fish.png"
    ]
    
    source_path = None
    for name in possible_names:
        if os.path.exists(name):
            source_path = name
            break
    
    if not source_path:
        print("❌ Fish image not found! Please save your fish image as one of:")
        for name in possible_names[:4]:  # Show first 4 options
            print(f"   - {name}")
        return False
    
    output_path = "background.png"
    
    try:
        print(f"🐟 Processing your fish background image: {source_path}")
        
        # Open the image
        img = Image.open(source_path)
        print(f"✅ Loaded image: {img.size[0]}x{img.size[1]}")
        
        # Convert to RGBA for better compatibility
        if img.mode != 'RGBA':
            img = img.convert("RGBA")
        
        # Resize to exact window dimensions (750x650)
        img = img.resize((750, 650), Image.Resampling.LANCZOS)
        print(f"✅ Resized to window dimensions: 750x650")
        
        # Apply a subtle white overlay to make text more readable
        # Create a semi-transparent white layer
        overlay = Image.new('RGBA', (750, 650), (255, 255, 255, 30))  # Very light overlay
        img = Image.alpha_composite(img, overlay)
        print("✅ Applied subtle overlay for better UI readability")
        
        # Save the processed image
        img.save(output_path)
        print(f"✅ Saved processed fish background as: {output_path}")
        
        print("\n🌊 Background processed successfully!")
        print("The fish will swim peacefully behind your hand control interface!")
        
        return True
        
    except Exception as e:
        print(f"❌ Error processing image: {e}")
        return False

if __name__ == "__main__":
    success = process_fish_background()
    if success:
        print("\n🌊 Your fish background is ready!")
        print("Restart your Hand Control Interface to see the fish swimming behind your controls!")
    else:
        print("\n⚠️ Save your fish image as 'fish_scene.jpg' first, then run this script.")
