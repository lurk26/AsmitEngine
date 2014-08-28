#region Using Statements
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Storage;
using Microsoft.Xna.Framework.GamerServices;
#endregion

namespace CHAMELEON
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class main : Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        Texture2D image;
        Texture2D background;
        Vector2 cham_position = new Vector2();
        Vector2 tongue_position = new Vector2();


        public main()
            : base()
        {
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferWidth = 1600;
            graphics.PreferredBackBufferHeight = 1050;
            graphics.ApplyChanges();
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            
            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            image = Content.Load<Texture2D>("temp/chameleon");
            background = Content.Load<Texture2D>("temp/bg");
            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
            Content.Unload();
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>

               
        protected override void Update(GameTime gameTime)
        {
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();
            if (Keyboard.GetState().GetPressedKeys().Length > 0)
            {
                float x=.0f, y=.0f;
                if (Keyboard.GetState().IsKeyDown(Keys.Left)) x = -3;
                if (Keyboard.GetState().IsKeyDown(Keys.Right)) x = 3;
                if (Keyboard.GetState().IsKeyDown(Keys.Down)) y = 3;
                if (Keyboard.GetState().IsKeyDown(Keys.Up)) y = -3;
                cham_position.X += x % graphics.PreferredBackBufferWidth;
                cham_position.Y += y % graphics.PreferredBackBufferHeight;
            }
            /*
            if(Mouse.GetState().LeftButton == ButtonState.Pressed)
            {
                float dirX = Mouse.GetState().X - x;
                float dirY = Mouse.GetState().Y - y;
                Vector2 direction = new Vector2(dirX, dirY);
                direction.Normalize();
               // move_chameleon += direction*5.0f;
               // x = move_chameleon.X;
               // y = move_chameleon.Y;
            }
            */
            updateGravity();
            // TODO: Add your update logic here

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            // TODO: Add your drawing code here
            spriteBatch.Begin();
            spriteBatch.Draw(background,new Rectangle(0,0,graphics.PreferredBackBufferWidth,graphics.PreferredBackBufferHeight), Color.Wheat);
            spriteBatch.Draw(image, cham_position, Color.White);
            spriteBatch.End();

            base.Draw(gameTime);
        }

        private void updateGravity()
        {
            float gravity = 2.8f;
            cham_position.Y += gravity;
        }

    }
}
